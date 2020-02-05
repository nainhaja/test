#include "stdio.h"
#include "get_next_line.h"
#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
float x = 0,xx = 0;
float y = 0,yy = 0;
int *tx,*ty;
int p = 0,indice = 0,indicee = 0;
int a=0,h=0,k=0;
float cptt = 0;
char **b;
int speed = 2;
float rotationangle = 0;
int walkdirection=0;
int turndirection=0;
void *mlx_ptr;
void *win_ptr;
void	ft_putnbr(int a);
int s=0,z=1,o=0;
void ft_draw(void *mlx_ptr,void *win_ptr)
{
    int color = 0;
    int i=0,j=0,cpt=32,cpt1=32;
    while (k <= a)
    {
        while(b[k][h] == '1' || b[k][h] == '0'|| b[k][h] == 'N' )
        {
            if(b[k][h] == '0')
                color = 0xFFFFFF;
            else if(b[k][h] == '1')
            {
                color = 0x6497b1;
                
            }
            else if(b[k][h] == 'N')
            {
                color = 0xFFFFFF;
                
                xx = (float)i;
                yy = (float)j;
                //mlx_pixel_put(mlx_ptr,win_ptr,x,y,0x6497b1);
               
            }
            while (i < cpt)
            {
                while(j < cpt1)
                {
                    mlx_pixel_put(mlx_ptr,win_ptr,i,j,color);
                    j++;
                }
                
                j = j - 32;
                //cpt3++;
                //cpt1 = cpt1 + 32;
                i++;
            }
            cpt = cpt + 32;
            h++;
        }
        i=0;
        j =j+32;
        cpt = 32;
        cpt1=cpt1+32;
        k++;
        h = 0;
        /*if(color == 0x6497b1)
        tx[cpt3] = cpt;
        ty[cpt3] = cpt;
        cpt3++;*/

    }
    k = 0;
    h = 0;
}

int key_press(int key)
{
    if(key == 123)
        indice = 1;
    if(key == 124)
        indice = -1;
    if(key == 126)
        indicee = 1;
    if(key == 125)
        indicee = -1;
    return 0;
}
int key_release(int key)
{

    if(key == 123)
        indice = 0;
    if(key == 124)
        indice = 0;
    if(key == 126)
        indicee = 0;
    if(key == 125)
        indicee = 0;
    return 0;   
}
int update()
{
    mlx_hook(win_ptr,2,0,key_press,0);
    mlx_hook(win_ptr,3,0,key_release,0);
    mlx_clear_window(mlx_ptr,win_ptr);
    ft_draw(mlx_ptr,win_ptr);
    rotationangle -= indice * (M_PI / 180) * 3;
        x += (cos(rotationangle)) * 2 * indicee;
        y += (sin(rotationangle)) * 2 * indicee;
    while(k <= a)
    {
        while(b[k][h] == '1' || b[k][h] == '0'|| b[k][h] == 'N')
        {
            if(b[k][h] == '1')
            {
                if((int)x/32 == h && (int)y/32 == k)
                {
                    x -= (cos(rotationangle)) * 2 * indicee;
                    y -= (sin(rotationangle)) * 2 * indicee;
                }
            }
            h++;
        }
        h = 0;      
        k++;
    }
    k = 0;
    h = 0;
    p=20;
    s = 0;
    z = 1;
    while(s < 60)
    {
        if(s == 30)
        {
            rotationangle -= (M_PI / 180 * s);
            z = z * (-1);
        }
        rotationangle += ((M_PI / 180) * z);
        p = 20;
        while(p > 0)
        {
            while(k <= a)
            {
                while(b[k][h] == '1' || b[k][h] == '0'|| b[k][h] == 'N')
                {
                    if(b[k][h] == '1')
                    {
                    if((int)(x+cos(rotationangle)*p)/32 == h && (int)(y+sin(rotationangle)*p)/32 == k)
                    {
                        o = 1;
                    }
                }
                h++;
            }
            h = 0;      
            k++;
        }
        k = 0;
        h = 0;
        if (o != 1)
            mlx_pixel_put(mlx_ptr,win_ptr,x+cos(rotationangle)*p,y+sin(rotationangle)*p,0xFF0000);
        p--;
        o = 0;
        }
        s++;
    }
    rotationangle += (M_PI / 180 * 30);
    
    return 0;
}

int main()
{
    char *t; 
    b = malloc(sizeof(char**) * 10);
    tx = malloc(sizeof(int) * 50);
    ty = malloc(sizeof(int) * 50);
    //int i = 0;
    int fd1 = open("text.txt", O_RDONLY);
    
    int color = 0;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr,500,500,"mlx 42");
    while (get_next_line(fd1,&t))
    {
        b[a] = t;
        a++;
    }
    b[a] = t;
    ft_draw(mlx_ptr,win_ptr);
    //printf("kds");
    x = xx;
    y = yy;
    mlx_pixel_put(mlx_ptr,win_ptr,x,y,0x6497b1);
    p=1;
    while(p < 20)
    {
        mlx_pixel_put(mlx_ptr,win_ptr,x+cos(rotationangle)*p,y+sin(rotationangle)*p,0xFF0000);
       p++;
    }
    
    mlx_loop_hook(mlx_ptr,update,(void*)0);
    //mlx_key_hook(win_ptr,deal_keyy,(void*)0);
    //mlx_lo
    mlx_loop(mlx_ptr);
    
}
