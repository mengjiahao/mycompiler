void printf();

int func(int a, char b) {
return a+b;
}

int revFunc(int a) {
int b;
if (a == 0) 
return 0;


b = 1 + revFunc(a-1);
return b;
}

class A {

int a;

void setA(int t) {
a = t;
}

int getA() {
return a;
}

};

class B : A {
int b;

void setA(int t) {
a = t * t * t;
}

int getA() {
return a;
}

void setB(int a, int c) {
b = a + c;
}

int getB() {
return b;
}

};



int main() {

char a = 'a';
int b = 2;
int c = 3;
int d = 4;
int i = 5;


class A ca;
class B cb;

ca = new A();
cb = new B();

printf("hello world!\n");
 
++d;
printf("%d\n", d);
--d;
printf("%d\n", d);
d += c;
printf("%d\n", d);
d -= c;
printf("%d\n", d);
d *= c;
printf("%d\n", d);
d = d / c;
printf("%d\n", d);
d = c - d * i;
printf("%d\n", d);
d = func(b, c);
printf("func:%d\n", d);
d = revFunc(3);
printf("revFunc:%d\n", d);

printf("class!\n");

ca.setA(100);
d = ca.getA();
printf("%d\n", d);

ca.a = a;
printf("%d\n", ++ca.a);


d = 1;
 
 while(i > 0) {
     c *= 2;
 
     if(i == 1) {
  	cb.setA(3);
	d = cb.getA();
	printf("(i%d) %d\n", i, d);
	
 	cb.setB(c, b);
 	d = cb.getB();	 
 	printf("(i%d) %d, %d\n", i, c, d);
 	
     } else {
  
     int e = 6;
     int f = 7;
     int g = 8;
     int h = 9;
     
     if (e * h + f * g > h) {
     	printf("(i%d) e * h + f * g: %d\n", i, e * h + f * g);
     	printf("(i%d) h: %d\n", i, h);
     }
     
  
     if (e > f || (f < g && g < h)) {
  	   d += 1;
  	   printf("%d\n", d);
     }
  
  }
  
    --i;
 }

delete ca;
delete cb;

return 0;
}
