#include <stdio.h>
#include <stdbool.h>
bool is_year(int year);
int main(void)
{
	int month_day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};//月数 
	int age;//年龄 
	int year_birth;//出生日期 
	int month_birth;
	int day_birth;
	int year_now;//当前日期 
	int month_now;
	int day_now;
	char ch;//读斜线 
	while(1){ 
	int day_data = 0;//距离下一次生日日期 
	printf("日期格式为year/month/day");
	printf("输入出生日期:");
	scanf("%d %d %d",year_birth, month_birth, day_birth);
	printf("输入当前日期:");
	scanf("%d %d %d", year_now, month_now, day_now);
	
	age = year_now - year_birth;//计算年龄 
	if(month_birth>month_now)
		age--;
	else if(month_birth<month_now)
		age;
	else if(month_birth==month_now)
	{
		if(day_now>=day_birth)
			age;
		else
			age--;
	}//年龄计算完毕
	printf("你的年龄为: ", age); 
	int year_next;//下一次生日日期 
	int month_next = month_birth;
	int day_next = day_birth; 
	if(age==year_now-year_birth)
	{
		year_next = year_now+1;//生日在下一年
		if(is_year(year_now))//当前年是否为闰年 
		{
			month_day[1] = 29;
			for(int i=month_next;i<month_now;i++)
				day_data += month_day[i-1];
			day_data -=day_next;
			day_data += day_now;
			if(is_year(year_next))//下一年是否为闰年 
				day_data = 366 - day_data;
			else
				day_data = 365 - day_data;
		}
		else//非闰 
		{
			month_day[1] = 28;
			for(int i=month_next;i<month_now;i++)
				day_data += month_day[i-1];
			day_data -=day_next;
			day_data += day_now;
			if(is_year(year_next))
				day_data = 366 - day_data;
			else
				day_data = 365 - day_data;
		} 
	}
	else
	{
		year_next = year_now;//生日在本年
		if(is_year(year_next))//是闰年 
		{
			month_day[1] = 29;
			for(int i=month_now;i<month_next;i++)
				day_data += month_day[i-1];
			day_data -= day_now;
			day_data += day_next;
		}
		else
		{
			month_day[1] = 28;
			for(int i=month_now;i<month_next;i++)
				day_data += month_day[i-1];
			day_data -= day_now;
			day_data += day_next;
		} 
	}
	printf("距离你下次生日还有%s", day_data, "天");
	day_data = 0;
}
	return 0;
}
bool is_year(int year)
{
	if(year%4==0&&year%100!=0)
		return true;
	else if(year%400==0)
		return true;
	else
		return false;
}