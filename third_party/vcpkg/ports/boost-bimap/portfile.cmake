# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/bimap
    REF boost-${VERSION}
    SHA512 1bd2a7d5d07c1a96ece6dd3683374212b89343aa7096d2631f6fd8e4650f34e5cdca5cd920ad5a4d8d06adc190b890041343c89827a98cb2eac2de66da463979
    HEAD_REF master
)

set(FEATURE_OPTIONS "")
boost_configure_and_install(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS ${FEATURE_OPTIONS}
)