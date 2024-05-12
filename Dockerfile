# Используем образ stateoftheartio/qt6:6.3-macos-aqt
FROM stateoftheartio/qt6:6.3-macos-aqt

# Копируем файлы проекта внутрь контейнера
COPY . /home/user/project

# Устанавливаем рабочую директорию
WORKDIR /home/user

# Запускаем сборку проекта
RUN qt-cmake ./project -G Ninja -B ./build && cmake --build ./build
