#pragma once
#include<stack>
#include<iostream>
using namespace std;

bool IsOperator(char ch)
{
	char ops[] = "+-*/";
	for (int i = 0; i < 4; i++){
		if (ch == ops[i])
			return 1;
	}
	return 0;
}

int Precedence(char op1, char op2)
{
	if (op1 == '(')
		return -1;
	if (op1 == '+' || op1 == '-'){
		if (op2 == '*' || op2 == '/')
			return -1;
		else
			return 0;
	}
	if (op1 == '*' || op1 == '/'){
		if (op2 == '+' || op2 == '-')
			return 1;
		else
			return 0;
	}
}

void inFix2PostFix(char* inFix, char* postFix)
{
	int j = 0, len;
	char c;
	stack<char> st;
	len = strlen(inFix);
	for (int i = 0; i < len; i++){
		c = inFix[i];
		if (c == '(')
			st.push(c);
		else if (c == ')'){
			while (st.top() != '('){
				postFix[j++] = st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			if (!IsOperator(c))
				st.push(c);
			else{
				while (st.empty() == false && Precedence(st.top(), c) >= 0){
					postFix[j++] = st.top();
					st.pop();
				}
				st.push(c);
			}
		}
	}

	while (st.empty() == false){
		postFix[j++] = st.top();
		st.pop();
	}
	postFix[j] = 0;
}

double postFixEval(char* postFix)
{
	stack<char> st;
	stack<int> num;
	int len = strlen(postFix);
	char c;
	for (int i = 0; i < len; i++){
		c = postFix[i];
		if (c == ' ') continue;
		if (!IsOperator(c))
			num.push(c - '0');
		else{
			int op1, op2;
			int val;
			op1 = num.top();
			num.pop();
			op2 = num.top();
			num.pop();
			switch (c){
				case '+':
					val = op1 + op2;break;
				case '-':
					val = op2 - op1;break;
				case '*':
					val = op1 * op2;break;
				case '/':
					val = op2 / op1;break;
				}
			num.push(val);
			printf("val:%d \n", val);
		}
	}
	return num.top();
}

int getCalc()
{
	char inFix[100];
	char postFix[100];
	int val;
	int times;
	printf("Please input the number of expressions:");
	scanf_s("%d", &times);
	getchar();
	while (times--)
	{
		printf("Enter an expression:\n");
		gets_s(inFix);
		if (strlen(inFix) == 0)
			continue;
		printf("\n%s = ", inFix);
		inFix2PostFix(inFix, postFix);
		printf("%s = ", postFix);
		val = postFixEval(postFix);
		printf("%d\n", val);
	}
	return 0;
}