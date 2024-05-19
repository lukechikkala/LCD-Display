#include "DEV_Config.h" 
#include "LCD_1in47.h"  
#include "GUI_Paint.h"  
#include "GUI_BMP.h"    
#include "test.h"       
#include "image.h"      
#include <stdio.h>      // printf()
#include <stdlib.h>     // exit()
#include <signal.h>     // signal()

void LCD_1IN47_test(void)
{
    signal(SIGINT, Handler_1IN47_LCD);
    if(DEV_ModuleInit() != 0){
        DEV_ModuleExit();
        exit(0);
    }
    printf("1.47inch LCD demo...\r\n");
    LCD_1IN47_Init(HORIZONTAL);
    LCD_1IN47_Clear(BLACK);
    LCD_SetBacklight(1023);
    UWORD *BlackImage;
    UDOUBLE Imagesize = LCD_1IN47_HEIGHT * LCD_1IN47_WIDTH * 2;
    printf("Imagesize = %d\r\n", Imagesize);
    if((BlackImage = (UWORD *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        exit(0);
    }
    Paint_NewImage(BlackImage, LCD_1IN47_WIDTH, LCD_1IN47_HEIGHT, 90, BLACK, 16);
    Paint_Clear(BLACK);
    printf("drawing...\r\n");

    const char* Text = "Hello World";

    Paint_DrawString_EN(
                            /* X-Start    */  ( LCD_1IN47_HEIGHT / 2 ) - 100
                            /* Y-Start    */ ,LCD_1IN47_WIDTH  / 2
                            /* String     */ ,Text
                            /* Font       */ ,&Font24
                            /* Fill Color */ ,BLACK
                            /* Text Color */ ,BRRED
                        );

    LCD_1IN47_Display(BlackImage);
    DEV_Delay_ms(1000);

    free(BlackImage);
    BlackImage = NULL;
    DEV_ModuleExit();
}