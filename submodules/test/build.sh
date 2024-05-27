#!/usr/bin/env sh
#
download_dir=.downloads
cef_branch=master

export CEF_INSTALL_SYSROOT=arm64
export GN_DEFINES="is_official_build=true use_sysroot=true symbol_level=1 is_cfi=false use_thin_lto=false chrome_pgo_phase=0"
export CEF_ARCHIVE_FORMAT=tar.bz2
python3 automate-git.py --download-dir=$download_dir --branch=$cef_branch --minimal-distrib --client-distrib --force-clean --build-target=cefsimple --arm64-build
