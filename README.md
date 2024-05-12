Инструкция по запуску:

1) Убедитесь, что у Вас установлен homebrew и введите следующие команды:
brew install g++
brew install cmake
brew install qt

2) Склонируйте удаленный репозиторий, предварительно установив git:

git clone git@gitlab.akhcheck.ru:kirill.grinko/box-with-molecules.git

3) Проверьте, что переменная окружения Qt6_DIR равна путю к папке с библиотекой Qt:

4) Выполните сборку проекта:

cmake -B build
cd build
make

5) Запустите симуляцию (из директории bin):

./box_with_molecules

В файле constants.h присутствуют константы BOX_WIDTH и BOX_HEIGHT, отвечащие за ширину и высоту области молекулярной симуляции.