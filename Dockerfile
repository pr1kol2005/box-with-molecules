FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    qt6-base-dev \
    libxcb-xinerama0 \
    libxcb-image0 \
    libxcb-keysyms1 \
    libxcb-render-util0 \ 
    libxcb-xkb1 \
    libxkbcommon-x11-0

COPY . /app

WORKDIR /app

USER root

ENV QT_DEBUG_PLUGINS=1

#ENV XDG_RUNTIME_DIR=/tmp

# RUN chmod 0700 /tmp

RUN cmake -B build && cmake --build build --target box_with_molecules

CMD ["./build/box_with_molecules"]
