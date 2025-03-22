# Use an official Ubuntu as the base image
FROM ubuntu:24.04

# Set environment variables to prevent prompts
ENV DEBIAN_FRONTEND=noninteractive


# Install dependencies needed for building protobuf and your project
RUN apt-get update && apt-get install -y \
    build-essential \
    curl \
    cmake \
    git \
    wget \
    unzip \
    autoconf \
    automake \
    libtool \
    python3 \
    python3-pip \
    libssl-dev \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y g++

RUN apt-get update && apt-get install -y protobuf-compiler libprotobuf-dev

# Clone the protobuf repository and checkout v30.4
# Install protobuf v30.4 (download and build from source)

    # Set environment variables (ensure that protobuf binaries are in the PATH)
ENV PATH="/usr/local/bin:$PATH"
ENV LD_LIBRARY_PATH="/usr/local/lib:$LD_LIBRARY_PATH"
ENV PKG_CONFIG_PATH="/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH"

# Set working directory
WORKDIR /app

# Copy the entire C++ project into the container
COPY . /app

# RUN mkdir include/protobuf
# RUN git clone --branch v30.1 --single-branch https://github.com/protocolbuffers/protobuf.git /app/include/protobuf

# WORKDIR /app/include/protobuf
# RUN mkdir build && cd build \
#     && cmake .. \
#     && make -j$(nproc) \
#     && make install

RUN mkdir build

WORKDIR /app/build
RUN cmake .. 
RUN make

# Expose the port the C++ service will listen on
EXPOSE 56000

# Run the compiled C++ executable
CMD ./exchange