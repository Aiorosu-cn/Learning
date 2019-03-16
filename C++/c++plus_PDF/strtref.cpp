//strc_ref.cpp --using structure references
#include <iostream>
#include <string>
struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main()
{
//partial initializations - remaing members set to 0，参数初始化-默认的参数设置为0
	free_throws one = {"ifelsa branch", 13,14};
	free_throws two = {"andor knott", 10,16};
	free_throws three = {"minnie max", 7,9};
	free_throws four = {"whily lopper", 5,9};
	free_throws five = {"long long",6,14};
	free_throws team = {"Throwgoods", 0, 0};
//no initialization未初始化
	free_throws dup;

	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);
//use reture value as argument
	display(accumulate(team, two));//这里为什么会有两个参数，明明在声明中只有1个参数
	accumulate(accumulate(team, three),four);
	display(team);
//use return value in assignment
	dup =  accumulate(team ,five);
	std::cout << "displaying team:\n";
	display(team);
	std::cout << "displaying dup after assignment:\n";
	display(dup);
	set_pc(four);
//ill-advised assignment
	accumulate(dup,five) = four;
	std::cout << "displaying dup after ill-advised assignment:\n";
	display(dup);
	return 0;
}

void display(const free_throws & ft)
{
	using std::cout;
	cout << "name: " << ft.name << '\n';
	cout << " made: " << ft.made << '\t';
	cout << "attempts: " << ft.attempts << '\t';
	cout << "percent: " << ft.percent << '\n';
}

void set_pc(free_throws & ft)
{
	if (ft.attempts !=0 )
		ft.percent = 100.0f * float(ft.made)/float(ft.attempts);
	else
		ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
} 
