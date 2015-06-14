class A {
    int a;
    
    void setA(int a_t) {
        a = a_t;
    }
    
    int getA() {
    	return a;
    }
};

class B : A {
     float b;
     
     void setAB(int a_t, float b_t) {
     	a = a_t;
     	b = b_t;
     }
};

int main() {
    int x, y;
    
    class B cb = new B();
    
    
    x = 1;
    y = cb.setAB(x, 9);
    
    if (x > y) {
    	x -= 4;
    } else {
       y *= 8;
    }
    
    delete cb;
    
    return 0;
}
