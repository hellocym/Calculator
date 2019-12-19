#include<bits/stdc++.h>
using namespace std;

string s;
stack<string> num;
stack<string> op;
stack<string> rvs_tmp;
// * / 3 4
// + - 1 2

void bkt_pop(){
	while(op.top() != "("){
		num.push(op.top());
		op.pop();
	}
	op.pop();
}

int grade(string x){
	switch(x[0]){
		case '+':case '-':
			return 1;
		break;
		case '*':case '/':
			return 2;
		break;
	}
	//return -1;//栈底
}

void op_push(string x){
	/*if(!op.empty())
		cout << op.size() << " " << endl;
	else
		cout << "empty" << endl;*/
	if(op.empty() || (op.top() == "(")){//op为空或op顶为(
		//cout << op.top() << " " << endl;
		op.push(x);
		return;
	}
	while(!op.empty()){//op顶为运算符
		if(!(grade(x) <= grade(op.top())))
			break;
		//cout << op.top() << " " << endl;
		//cout << grade(op.top()) << endl;
	
		num.push(op.top());
		op.pop();
	}
	op.push(x);
	
	//cout << op.top() << " ";
}

int main(){
//op.push('@');//栈底
	cin >> s;
	string tmp = "";
	for(int i = 0; i <= s.length() - 1; i++){
		//cout << i << " ";
		if(s[i] >= '0' && s[i] <= '9'){
			tmp += s[i];
			if(i == s.length() - 1){
				num.push(tmp);
				tmp = "";
			}
		}
		else if(s[i] == '('){
			if(!tmp.empty()){
				num.push(tmp);
				tmp = "";
			}
			op.push("(");
		}
		else if(s[i] == ')'){
			if(!tmp.empty()){
				num.push(tmp);
				tmp = "";
			}
			bkt_pop();
		}
				
		else{//+*-/
			if(!tmp.empty()){
				num.push(tmp);
				tmp = "";
			}
			string op_push_tmp = "";
			op_push_tmp += s[i];
			//cout << op_push_tmp << " ";
			//cout << (op.empty() || op.top() == "(") << endl;
			op_push(op_push_tmp);
			//cout << op.top() << " ";
		}
		//cout << endl;
	
	}
	
	while(!op.empty()){
		if(op.top()!="(")
			num.push(op.top());
		op.pop();
	}
	while(!num.empty()){
		rvs_tmp.push(num.top());
		num.pop();
	}
	while(!rvs_tmp.empty()){
		cout << rvs_tmp.top() << " ";
		rvs_tmp.pop();
	}
	
	cout << endl;
	return 0;
}
