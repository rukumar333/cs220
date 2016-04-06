int myfunc(int a,int b) {
	int c;
	while(a<10) {
		c+=b;
		a--;
	}
	return c;
}

int main() {
	int ma;
	ma=myfunc(3,4);
	return 0;
}
