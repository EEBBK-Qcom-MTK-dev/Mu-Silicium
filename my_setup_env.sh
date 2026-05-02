#!/bin/bash

# Colors for output
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
NC='\033[0m' # No Color

# Function to display Help Message
function _help(){
    echo "Usage: setup_env.sh -p <Package Manager> [OPTIONS]"
    echo
    echo "Install all needed Packages for Mu-Silicium development."
    echo
    echo "Options:"
    echo "  -p, --package-manager PAK  Choose your Package Manager (apt/dnf/pacman/zypper/apk)"
    echo "  -v, --venv                  Create Python virtual environment"
    echo "  -n, --no-upgrade            Skip system upgrade (for CI/CD)"
    echo "  -s, --skip-python           Skip Python packages installation"
    echo "  -h, --help                  Show this help message"
    echo 
    echo "MainPage: https://github.com/Project-Silicium/Mu-Silicium"
    exit 0
}

# Functions to display the Message Type
function _error(){ echo -e "${RED}❌ ERROR: ${@}${NC}" >&2; exit 1; }
function _warn(){ echo -e "${YELLOW}⚠️  WARNING: ${@}${NC}" >&2; }
function _info(){ echo -e "${BLUE}ℹ️  INFO: ${@}${NC}" >&2; }
function _success(){ echo -e "${GREEN}✅ ${@}${NC}" >&2; }

# Initialize variables
PAK=""
CREATE_VENV=false
SKIP_UPGRADE=false
SKIP_PYTHON=false

# Parse arguments
OPTS=$(getopt -o p:vnhs --long package-manager:,venv,no-upgrade,help,skip-python -n 'setup_env.sh' -- "$@") || exit 1
eval set -- "${OPTS}"

while true; do
    case "${1}" in
        -p|--package-manager) PAK="${2}"; shift 2 ;;
        -v|--venv) CREATE_VENV=true; shift ;;
        -n|--no-upgrade) SKIP_UPGRADE=true; shift ;;
        -s|--skip-python) SKIP_PYTHON=true; shift ;;
        -h|--help) _help; shift ;;
        --) shift; break ;;
        *) _error "Invalid option: ${1}";;
    esac
done

# Check if Package Manager is specified
if [[ -z "${PAK}" ]]; then
    _error "Package manager not specified. Use -p to specify one."
fi

# Detect distribution
detect_distro() {
    if [[ -f /etc/os-release ]]; then
        . /etc/os-release
        echo "$ID"
    else
        _error "Cannot detect distribution"
    fi
}

# Check if running as root
if [[ $EUID -eq 0 ]]; then
    _warn "Running as root. It's recommended to run as a regular user with sudo privileges."
fi

# Install packages based on package manager
_info "Installing packages for ${PAK} package manager..."

case "${PAK}" in
    apt|apt-get)
        if [[ ${SKIP_UPGRADE} == false ]]; then
            _info "Updating package lists..."
            sudo apt update || _warn "Failed to update package lists"
            
            if [[ "${CI_BUILD}" != "true" ]]; then
                _info "Upgrading system packages..."
                sudo apt upgrade -y || _warn "System upgrade completed with warnings"
            fi
        fi
        
        _info "Installing development packages..."
        sudo apt install -y \
            pip \
            git \
            mono-devel \
            build-essential \
            lld \
            uuid-dev \
            nasm \
            gcc-aarch64-linux-gnu \
            python3 \
            python3-git \
            python3-pip \
            gettext \
            locales \
            gnupg \
            ca-certificates \
            python3-venv \
            git-core \
            clang \
            llvm \
            curl \
            lld \
            qemu-user-static \
            crossbuild-essential-arm64 \
            || _error "Failed to install packages"
        ;;
        
    dnf|yum)
        if [[ ${SKIP_UPGRADE} == false ]]; then
            _info "Updating package lists..."
            sudo dnf check-update || _warn "Failed to check for updates"
        fi
        
        _info "Installing development packages..."
        sudo dnf install -y \
            git \
            mono-devel \
            nuget \
            nasm \
            make \
            lld \
            gcc \
            automake \
            gcc-aarch64-linux-gnu \
            python3 \
            python3-pip \
            gettext \
            gnupg \
            ca-certificates \
            git-core \
            clang \
            llvm \
            curl \
            lld \
            qemu-user \
            || _error "Failed to install packages"
        ;;
        
    pacman|yay|paru)
        if [[ ${SKIP_UPGRADE} == false ]]; then
            _info "Updating system..."
            sudo pacman -Syu --noconfirm || _warn "System update completed with warnings"
        fi
        
        _info "Installing development packages..."
        sudo pacman -S --noconfirm --needed \
            git \
            mono \
            base-devel \
            nuget \
            lld \
            nasm \
            aarch64-linux-gnu-gcc \
            python3 \
            python \
            python-distutils-extra \
            python-pip \
            gettext \
            gnupg \
            ca-certificates \
            python-virtualenv \
            python-pipenv \
            clang \
            llvm \
            curl \
            lld \
            qemu-user-static \
            util-linux \
            || _error "Failed to install packages"
        ;;
        
    zypper)  # openSUSE support
        if [[ ${SKIP_UPGRADE} == false ]]; then
            _info "Refreshing repositories..."
            sudo zypper refresh || _warn "Failed to refresh repositories"
        fi
        
        _info "Installing development packages..."
        sudo zypper install -y \
            git \
            mono-devel \
            nuget \
            nasm \
            make \
            lld \
            gcc \
            gcc-c++ \
            gcc-aarch64-linux-gnu \
            python3 \
            python3-pip \
            gettext \
            gnupg \
            ca-certificates \
            git-core \
            clang \
            llvm \
            curl \
            lld \
            qemu-linux-user \
            || _error "Failed to install packages"
        ;;
        
    apk)  # Alpine Linux support
        if [[ ${SKIP_UPGRADE} == false ]]; then
            _info "Updating package index..."
            sudo apk update || _warn "Failed to update package index"
        fi
        
        _info "Installing development packages..."
        sudo apk add \
            git \
            mono-dev \
            nuget \
            nasm \
            make \
            lld \
            gcc \
            g++ \
            aarch64-linux-gnu-gcc \
            python3 \
            py3-pip \
            gettext \
            gnupg \
            ca-certificates \
            git \
            clang \
            llvm \
            curl \
            lld \
            qemu-user-static \
            util-linux-dev \
            || _error "Failed to install packages"
        ;;
        
    *)
        _error "Invalid package manager: ${PAK}\nAvailable: apt, dnf, pacman, zypper, apk"
        ;;
esac

_success "System packages installed successfully!"

# Create Python virtual environment if requested
if [[ "${CREATE_VENV}" == true ]]; then
    _info "Creating Python virtual environment..."
    python3 -m venv venv || _error "Failed to create virtual environment"
    
    if [[ -f "venv/bin/activate" ]]; then
        source venv/bin/activate
        _success "Virtual environment activated"
    else
        _warn "Virtual environment created but could not be activated"
    fi
fi

# Install Python packages
if [[ "${SKIP_PYTHON}" == false ]]; then
    _info "Installing Python packages..."
    
    # Check if pip-requirements.txt exists
    if [[ ! -f "pip-requirements.txt" ]]; then
        _warn "pip-requirements.txt not found. Creating default requirements..."
        cat > pip-requirements.txt << 'EOF'
pip>=21.0
setuptools>=50.0
wheel>=0.35.0
toml>=0.10.0
pyyaml>=5.0
jinja2>=2.11.0
edk2-basetools
EOF
    fi
    
    # Try different pip installation methods
    if python3 -m pip install -r pip-requirements.txt; then
        _success "Python packages installed successfully"
    elif python3 -m pip install -r pip-requirements.txt --break-system-packages; then
        _success "Python packages installed with --break-system-packages flag"
    elif [[ -x "venv/bin/pip" ]]; then
        venv/bin/pip install -r pip-requirements.txt || _error "Failed to install pip packages in venv"
        _success "Python packages installed in virtual environment"
    else
        _warn "Failed to install Python packages via pip. Trying with --user flag..."
        python3 -m pip install --user -r pip-requirements.txt || _error "Failed to install pip packages"
    fi
fi

# Set up environment variables
export CLANGPDB_AARCH64_PREFIX="aarch64-linux-gnu-"
export ARCH="aarch64"
export CROSS_COMPILE="aarch64-linux-gnu-"

_info "Setting up environment variables..."
cat >> ~/.bashrc << EOF

# Mu-Silicium development environment
export CLANGPDB_AARCH64_PREFIX="aarch64-linux-gnu-"
export ARCH="aarch64"
export CROSS_COMPILE="aarch64-linux-gnu-"
export PATH="\$PATH:\$HOME/.local/bin"
EOF

# Verify installation
_info "Verifying installation..."
echo "=== Toolchain Verification ==="
which aarch64-linux-gnu-gcc && aarch64-linux-gnu-gcc --version | head -1
which clang && clang --version | head -1
which python3 && python3 --version
which pip && pip --version
echo "============================="

_success "Environment setup completed!"
echo ""
echo "Next steps:"
echo "1. Run 'source ~/.bashrc' to load environment variables"
echo "2. Check the Mu-Silicium documentation for build instructions"
echo "3. For CI/CD, you can use: $0 -p ${PAK} -n -s"
