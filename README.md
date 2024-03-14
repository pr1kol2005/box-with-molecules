Инструкция по запуску:

1) Убедитесь, что у Вас установлен homebrew и введите следующие команды:
brew install g++
brew install cmake
brew install qt

2) Склонируйте удаленный репозиторий, предварительно установив git:

git clone git@gitlab.akhcheck.ru:kirill.grinko/box-with-molecules.git

3) Создайте environment variable QT_DIR, которая указывает на директорию с установленной библиотекой Qt

4) Выполните сборку проекта:

cmake .. -B ./build
cd build
make

5) Запустите симуляцию:
./box_with_molecules