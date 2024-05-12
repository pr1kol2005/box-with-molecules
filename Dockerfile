#should work for non-arm64
FROM stateoftheartio/qt6:6.3-gcc-aqt

USER root

RUN apt update && apt install -y \
    libgl-dev \
    libvulkan-dev \
    fuse \
    libfuse2 \
    && rm -rf /var/lib/apt/lists/*

COPY . /home/user/project

WORKDIR /home/user/project

RUN qt-cmake ./ -G Ninja -B ./build && cmake --build ./build

CMD ./build/box_with_molecules

# RUN curl -Lo linuxdeploy https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage && \
#     chmod +x linuxdeploy && \
#     mv linuxdeploy /usr/local/bin/ && \
#     mkdir ./build/deploy

# CMD linuxdeploy --plugin qt -e "$(find ./build -maxdepth 1 -type f -executable)" --appdir ./build/deploy
