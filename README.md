## Инструкция по сборке и запуску 

1) Убедитесь, что у Вас установлен homebrew и введите следующие команды:

  ```
  $ brew install g++;
  $ brew install cmake;
  $ brew install qt
  ```

2) Склонируйте удаленный репозиторий, предварительно установив git:

  ```console
    $ git clone git@gitlab.akhcheck.ru:kirill.grinko/box-with-molecules.git
  ```

3) Проверьте, что переменная окружения Qt6_DIR равна путю к папке с библиотекой Qt:

4) Выполните сборку проекта:

  ```console
  $ cmake -B build;
  $ cmake --build build --target box_with_molecules
  ```

5) Запустите симуляцию:
  ```console
  $ bin/box_with_molecules
  ```

В файле ([constants.h](include/constants.h)) присутствуют константы `BOX_WIDTH` и `BOX_HEIGHT`, отвечащие за ширину и высоту области молекулярной симуляции.

Также Вы можете собрать и запустить тесты:

  ```console
  $ cmake --build build --target box_test;
  $ bin/box_test
  ```