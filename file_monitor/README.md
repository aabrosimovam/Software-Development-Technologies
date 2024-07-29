# file_monitor

Написать программу для слежения за состоянием выбранного файла.

С некоторой периодичностью нужно проверять:
1. Существует файл или нет;
2. Размер файла.

Программа выводит на консоль уведомление о произошедших изменениях в файле.

Состояния:
1. Файл существует, не пустой (на экран выводится факт существования файла и его размер)
2. Файл существует, но был изменен (на экран выводится факт существования файла, сообщение о том что файл был изменен и его размер)
3. Файл не существует (на экран выводится информация о том что файл не существует)