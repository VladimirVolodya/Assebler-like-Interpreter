# Assebler-like-Interpreter

## Сборка

1. Создайте новую директорию для сборки и переместитесь в нее:
```shell
mkdir build
cd build
```
2. Собственно, выполните сборку:
```shell
cmake .. && make
```

## Работа с программой

После сборки вы увидите файл `SM_Interpreter`, аргументы у программы следующие:
* Индекс интерпретируемой машины: `0` для двух-адресной, `1` для трех-адресной
* Путь к файлу с начальной конфигурацией памяти. В нем можно указать, какие числа по каким адресам в памяти лежат, а также значения регистров, если они есть у машины, если значения в регистрах не указаны, регистры заполняются случайными числами.
* Путь к файлу с кодом программы, интерпретатор проверит, что адреса команд идут в правильном порядке и ни одна команда не перекрывает другую.

## Некоторые подробности работы

* При попытке записи по адресу, который не был указан в конфигурационном файле для памяти будет выброшено исключение.
* При попытке чтения из памяти, не указанной в конфигурационном файле для памяти будет возвращено случайное число.
* Как уже было сказано, интерпретатор проверит правильность заполнения адресов с командами в исходном коде.
* Если программа не завершается явно (забыт вызов команды `Stop`), поведение интерпретатора не определено.
* Для двух-адресной машины нет unsigned-версий условных переходов по адресу, потому что в них значение в регистре сравнивается с нулем.
* После каждой выполненной команды интерпретатор печатает текущее состояние машины: все регистры (если они есть) и все отслеживаемые участки памяти (те, которые были указаны в конфигурационном файле для памяти).

## Пример

В репозитории лежат файлы `memory.txt` и `program_code.txt`, они нужны для запуска примера:
```shell
SM_Interpreter 1 memory.txt program_code.txt
```

В примере считается значение выражения `x^5 - 100x^3 + x`, если значение `x` записано в ячейке памяти с адресом `1000`, в примере это значение равно `2`, после подсчета результат кладется обратно в ячейку с адресом `1000`.