# C and C++ projects

### В этом разделе представлены реализованные мною проекты на языках программирования C и C++.

## Decimal

В этом проекте я реализовал библиотеку decimal.h на языке программирования C. 
Цель этой библиотеки — добавить возможность работы с типом «decimal», которого нет в стандарте языка. 
Однако этот тип очень важен. Например, для финансовых расчётов, где ошибки вычислений, характерные для типов с плавающей запятой, 
недопустимы. В рамках проекта я работал над задачами по обработке финансовой информации,
изучал вопросы внутреннего представления различных типов данных и структурированное программирование.

## Containers

В этом проекте я написал собственную библиотеку, реализующую базовые стандартные классы контейнеров C++: 
list, map, queue, set, stack и vector. Реализация представляет собой полный набор стандартных методов и атрибутов для работы с элементами, 
проверки ёмкости контейнера и итерации. 


## Brick Game v 1.0

В этом проекте я создал игру «Тетрис» в консольном варианте на языке программирования Си. 
Проект состоит из двух частей для реализации игры «Тетрис»: 
- библиотеки, реализующей логику игры, которую в будущем можно будет подключить к различным графическим интерфейсам
- интерфейса терминала. 

Логика библиотеки реализована с помощью конечных автоматов (FSM)

## Brick Game v 2.0

В этом проекте я создал две игры из проекта Brick Game: тетрис и змейка. 
Игры реализованы в консольном варианте и в десктопной версии (с помощью фреймворка QT).

Проект состоит из двух отдельных компонентов:
- библиотеки, отвечающей за реализацию игровой логики
- графического интерфейса для настольных компьютеров.

Игра разработана по паттерну MVC - Модель-представление-контроллер — это схема разделения модулей приложения на три отдельных макрокомпонента:
- модель, содержащую бизнес-логику
- представление — форму пользовательского интерфейса для взаимодействия с программой
- контроллер, который изменяет модель в зависимости от действий пользователя.
