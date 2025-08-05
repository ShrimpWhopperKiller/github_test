//윤년 계산기

#include <iostream>

class Date {
	int year_=2001;
	int month_=1;  //
	int day_=1;    // 
	bool yoonYear = false;
public:
	void checkYoonYear(int year) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			yoonYear = true;
		else
			yoonYear = false;
	}

	void SetDate(int year, int month, int date) {
		checkYoonYear(year);
		//
		if (((date >= 1 || date <= 31) && month != 2) || (date >= 1 || date <= 28) && month == 2)
			day_ = date;
		else if (month == 2 && yoonYear == true && (date >= 1 || date <= 29))
			day_ = date;
		else {
			std::cout << "날짜를 다시 확인해 주세요" << std::endl;
			return;
		}
		//
		if(month>=1||month<=12)
			month_ = month;
		else {
			std::cout << "월을 다시 확인해 주세요" << std::endl;
			return;
		}
		year_ = year;
		

	}
	void AddDay(int inc){
		int DayMax = 31;
		day_ += inc;
		while (1) {
			if (month_ == 2)
				DayMax = 28 + yoonYear;	//윤년이면 +1
			else
				DayMax = 31;

			if (day_ > DayMax) {
				day_ -= DayMax;
				AddMonth(1);
			}
			else
				break;
		}
	}
	void AddMonth(int inc) {
		if (month_ + inc >= 12) {
			year_ += (month_ + inc) / 12;
			month_ = (month_ + inc-1) % 12+1;
		}
		else
			month_+=inc;
	}
	void AddYear(int inc) {
		year_=year_+inc;
	}
	void ShowDate() {
		std::cout << "현재 날짜는 " << year_ <<"년 " <<month_<<"월 "<<day_<<"일 입니다." << std::endl;
	}
};


int select() {
	int temp;
	std::cout << "1.날짜 입력 2.년 추가 3.월 추가 4.일 추가 5.날짜 출력 6.종료" << std::endl;
	std::cin >> temp;
	return temp;
}

int main() {
	int pick;
	int year, month, day;
	Date date;
	while (1) {
		pick = select();
		switch (pick) {
		case 1:
			std::cout << "년도, 월, 일을 입력해 주세요 :" << std::flush;
			std::cin >> year >> month >> day;
			date.SetDate(year, month, day);
			break;
		case 2:
			std::cout << "추가할 년도를 입력해주세요 :" << std::flush;
			std::cin >> year;
			date.AddYear(year);
			break;
		case 3:
			std::cout << "추가할 월 입력 :" << std::flush;
			std::cin >> month;
			date.AddMonth(month);
			break;
		case 4:
			std::cout << "추가할 일 입력 :" << std::flush;
			std::cin >> day;
			date.AddDay(day);
			break;
		case 5:
			date.ShowDate();
			break;
		case 6:
			return 0;
		}
	}
	return 0;
}