int myfunc(int a,int b) {
	int c;
	for(c=0;c<a;c++) {
		b=b+a;
	}
	return b;
}

int main() {
	int ma;
	ma=myfunc(3,4);
	return 0;
}
