#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: ./compile.sh <source_file.c> <glibc_version>"
    echo "Example: ./compile.sh pwnme.c 2.35"
    echo "Supported glibc versions: 2.27, 2.31, 2.35, 2.39"
    exit 1
fi

SOURCE_FILE=$1
GLIBC_VERSION=$2
DOCKERFILE_NAME="compile.Dockerfile"

if [ ! -f "$SOURCE_FILE" ]; then
    echo "Error: Source file '$SOURCE_FILE' not found."
    exit 1
fi

if [ ! -f "$DOCKERFILE_NAME" ]; then
    echo "Error: Dockerfile '$DOCKERFILE_NAME' not found in the current directory."
    exit 1
fi


case "$GLIBC_VERSION" in
    "2.23") BASE_IMAGE="ubuntu:16.04" ;;
    "2.27") BASE_IMAGE="ubuntu:18.04" ;;
    "2.31") BASE_IMAGE="ubuntu:20.04" ;;
    "2.35") BASE_IMAGE="ubuntu:22.04" ;;
    "2.39") BASE_IMAGE="ubuntu:24.04" ;;
    *)
        echo "Error: Unsupported glibc version '$GLIBC_VERSION'."
        echo "Supported versions are: 2.27, 2.31, 2.35, 2.39"
        exit 1
        ;;
esac

echo "--- Preparing environment for glibc $GLIBC_VERSION using $BASE_IMAGE ---"

IMAGE_TAG="compiler-env:$(echo "$BASE_IMAGE" | tr ':' '-')"
echo "Building Docker image '$IMAGE_TAG' if it doesn't exist..."
docker build \
    --build-arg BASE_IMAGE="$BASE_IMAGE" \
    -t "$IMAGE_TAG" \
    -f "$DOCKERFILE_NAME" .



SOURCE_BASENAME=$(basename "$SOURCE_FILE")
OUTPUT_BINARY="${SOURCE_BASENAME%.c}"
COMPILER_FLAGS="-no-pie -g -fno-stack-protector"


echo "Compiling '$SOURCE_BASENAME' into '$OUTPUT_BINARY'..."

docker run \
    --rm \
    -v "$(pwd)":/work \
    "$IMAGE_TAG" \
    gcc $COMPILER_FLAGS -o "$OUTPUT_BINARY" "$SOURCE_BASENAME"

if [ -f "$OUTPUT_BINARY" ]; then
    echo "--- Compilation successful! ---"
    echo "Binary '$OUTPUT_BINARY' is now available in your current directory ($(pwd))."
    ls -l "$OUTPUT_BINARY"
    echo "To check glibc version, run: ldd $OUTPUT_BINARY"
else
    echo "--- Compilation failed. ---"
    echo "Check for errors in your source code."
fi
