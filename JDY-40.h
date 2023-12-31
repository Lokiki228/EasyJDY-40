



/*
	Coded by Lok 2023
	что имеем Сейчас
	- гибкая настройка модуля из программы
	- передача любого Stream объекта в класс
	- какое никакое энергосбережение в режиме симплекса
	- симплексный режим работы UART-моста(в разработке, но уже есть пара методов)
	- отчет об успешности выполнения настройки(ТОЛЬКО в режиме настройки через АТ): отправили команду - получаем данные с UART - и понимаем получили или нет
	- проверка наличия модуля на шине
	что имеем В будующем
	- наследование класса print
	- получение всех настроек с модуля
	- быстрая синхронизация двух систем по проводу(например вемос в связке с jdi), я еще не придумал поэтому не могу описать.
	
	
	Буду рад вашим дополнениям к библиотеке, а особенно дополнениям к оптимизации либы
	и алгоритмам парсинга ответов на запросы установленных параметров с модуля.
	Если есть какие-то идеи и дополнения к проекту прошу писать на lokkiki343@gmail.com
	
	
	ver 1.0 -> создание и небольшой тест.
	ver 1.1 -> оптимизация отправки(теперь 1 стринга в 15 байт, нормуль), разделил хеддер и си++
*/
#pragma once
#include <Arduino.h>


#define _SIMPLEX 0
#define _DUPLEX 1




class JDY40 {
	public://Инициализация
	JDY40(Stream* s); 
	
	void configDevice(bool mode, uint8_t cs, uint8_t set); //конфигурация устройства из программы
	bool begin(); //проверка наличия модуля
	void on();
	void off();
	bool setAllSettings(uint8_t baud, uint16_t rfid, uint16_t dvid, uint8_t rfc, uint8_t power);
	bool setBaud(uint8_t baud);
	bool setDevID(uint16_t dvid);
	bool setRfID(uint16_t rfid);
	bool setChannel(uint8_t rfc);
	bool setPower(uint8_t power);
	
	
	//Отправка в симплексе
	void print(String str);
	void print(const char* str);
	//coming soon... More, MORE!
	//Я х*й его знает как наследовать класс Print, поэтому пока так, елсли знаете пж скажите как :)
	//Потом начитаюсь, научусь, добавлю
	
	
	
	
	private:///////////////////////////////Приваты////////////////////////////////
	Stream* serial;
	String _send;
	
	bool _mode = 0;
	uint8_t _cs;
	uint8_t _set;
	bool _on;
	bool _err;
	bool _ok;
	bool yes;
	
	void are_you_ok(); //проверка на успешность
	void settings(bool state); //включение или выключение режима настроек 
	bool sendData(); //отправка данных настройки
};																																																																																																																							