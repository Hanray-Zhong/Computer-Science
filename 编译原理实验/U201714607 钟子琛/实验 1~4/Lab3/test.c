int a,b,c;
float m,n;
int Fibo(int a)
{
    if (a == 1 || a == 2) return 1;
    return Fibo(a-1)+Fibo(a-2);
}

int main()
{
    int m,n,i;
    i=1;
    while(i<=m)
    {
        n = Fibo(i);
        i=i+1;
    }
    return 1;
}