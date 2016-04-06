int myfunc(int a,int b) {
	int c;
	switch(a) {
		case 10 : c=a; break;
		case 11: b++;
		case 12:
		case 13: c=a+b; break;
		case 14: c=a*b; break;
		case 15: c=a+2; break;
		default: c=0;
	}
	return c;
}

int main() {
	int ma;
	ma=myfunc(3,4);
	return 0;
}
