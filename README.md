Инструкция по запуску:

1) Убедитесь, что у Вас установлен homebrew и введите следующие команды:
brew install g++
brew install cmake
brew install qt

2) Склонируйте удаленный репозиторий, предварительно установив git:

git clone git@gitlab.akhcheck.ru:kirill.grinko/box-with-molecules.git

3) В файле CMakeLists.txt замените путь к папке с библиотекой Qt в этой строке:

set(CMAKE_PREFIX_PATH <путь до папки>)

4) Выполните сборку проекта:

cmake .. -B ./build
cd build
make

5) Запустите симуляцию:
./box_with_molecules

В файле constants.h присутствуют константы BOX_WIDTH и BOX_HEIGHT, отвечащие непосредственно за ширину и высоту области молекулярной симуляции.