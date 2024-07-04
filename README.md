## Инструкция по сборке и запуску 

1) Убедитесь, что у Вас установлен homebrew и введите следующие команды:

  ```sh
  brew install g++;
  brew install cmake;
  brew install qt
  ```

2) Склонируйте удаленный репозиторий, предварительно установив git:

  ```sh
  git clone git@gitlab.akhcheck.ru:kirill.grinko/box-with-molecules.git
  ```

3) Проверьте, что переменная окружения Qt6_DIR равна путю к папке с библиотекой Qt:

4) Выполните сборку проекта:

  ```sh
  cmake -B build;
  cmake --build build --target box_with_molecules
  ```

5) Запустите симуляцию:
  ```sh
  bin/box_with_molecules
  ```

В файле [constants.h](include/constants.h) присутствуют константы `BOX_WIDTH` и `BOX_HEIGHT`, отвечащие за ширину и высоту области молекулярной симуляции.

Также Вы можете собрать и запустить тесты:

  ```sh
  cmake --build build --target box_test;
  bin/box_test
  ``` 

  ### Обработка данных

  В директории [data](data/) находится скрипт [research.py](data/research.py), который проверяет выполнение двумерного распределения Максвелла, анализируя данные о скоростях чатиц, сохраняемые во время выполнения симуляции. Наглядным примером выполнения распределния с хорошей точностью на заранее полученном набором данных является [scatter.gif](data/scatter.gif).