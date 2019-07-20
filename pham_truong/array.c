/***************************************************************************************************
****************            code: input array, output avegare array                 ****************
****************                  swap array and output new array                   ****************
****************            Design                                                  ****************
****************            Name : Pham Doan Truong                                 ****************
****************            Company :                                               ****************
***************************************************************************************************/


#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m=0;
    int n, k;
    float sum;
    int i, j, a[100], b[100], c[100];
    printf("nhap vao so phan tu cua mang:  ");
    scanf("%d",&n);
    
    /*nhap cac phan tu cua mang*/
    for(i=0;i<n;i++)
    {
        printf("a[%d]= ", i);
        scanf("%d",&a[i]);
    }
    printf("\n mang da nhap vao la\n\n");
    
    
    /**** in ra mang da nhap vao ****/
                                
    for(i=0;i<n;i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
    
    /*tinh trung binh cong*/
    sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    printf("trung binh cong cua mang la : ");
    printf("%f \n\n", sum/n);
    
/*doi cho phan tu chan le*/

j=k=0;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)                      //tim thay so chan thi chuyen sang mang b[j], con so le chuyen sang mang c[k]
        {
            b[j++]=a[i];
        }
        else c[k++]=a[i];
    }
    i=0;
    while(i<j) a[i]=b[i++];               // chuyen mang b[j] vao dau mang a[i]
    while(m<k)  a[i++]=c[m++];             // chuyen mang c[k] vao cuoi mang a[i]
    
/*in ra*/
    for(i=0;i<n;i++)
    {
        printf("%4d", a[i]);
    }
    getch();
    return 0;
}
