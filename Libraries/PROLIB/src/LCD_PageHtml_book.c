#include "LCD_PageHtml_book.h" 
 
 
 
/// 自模 设计 字宽 16 字高 16 
//  阴码  逐行 24 24 顺向 16进制  
//uint8_t test_modu[] ={ 
// 0x00,0x00,0x7F,0xFC,0x01,0x00,0x01,0x00,0x01,0x00,0x01,
// 0x00,0x01,0x00,0x3F,0xF8,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00 ,
// 0x01,0x00,0x01,0x00,0xFF,0xFE,0x00,0x00};/*"王",0*/

//#define _row_count  16
//#define _byte_count  2
//#define _bit_count   8
 
/// 自模 设计 字宽 32 字高 32 
//  阴码  逐行 24 24 顺向 16进制  
uint8_t test_modu2[] ={ 
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 ,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xC0,0x07,0xFF,0xFF,0xC0 ,
 0x04,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x01,0xFF,0xFF,0x00,0x03,0xFF,0xFF,0x00 ,
 0x03,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x1F,0xFF,0xFC,0x00,0x3F,0xFF,0xFF,0xFE ,
 0x7F,0x80,0x7F,0xFE,0x60,0x00,0x03,0xFC,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 ,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};/*"王",0*/ 

#define _row_count   32
#define _byte_count  4
#define _bit_count   8
void Display_Char_test(void){
  
  uint8_t row_count , byte_count , bit_count ;
  
  for(row_count = 0 ;row_count< _row_count; row_count++){
    
    printf("\n");
    
    for(byte_count = 0 ;byte_count< _byte_count ; byte_count++){
      
      for( bit_count = 0;bit_count < _bit_count ; bit_count++){
        
        if(test_modu2[row_count*_byte_count+byte_count] &(0x80 >>bit_count)){
           printf("*");
        }else{
          printf(" ");
        }
      }
    }
  }
}


//================================ 页面设计函数=======================================

/**
 * @brief  在ILI9341显示器上开辟一个窗口
 * @param  usX ：在特定扫描方向下窗口的起点X坐标
 * @param  usY ：在特定扫描方向下窗口的起点Y坐标
 * @param  usWidth ：窗口的宽度
 * @param  usHeight ：窗口的高度
 * @retval 无
 */
void  fn_Lcd_Page1(void){

//      printf("\n-->LCD %x",GB565(255, 193 ,98));
//      printf("\n-->LCD %x",GB888(0xFFC162));
  
      LCD_SetColors( GB888(0x589447), GB888(0xFFC162));
      ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* 清屏，显示 黄色的界面 */
      
      LCD_SetForeColor(GB888(0x589447)); //标题绿色的框
      ILI9341_DrawRectangle( 0,0,LCD_X_LENGTH,25,1,1);
      LCD_SetForeColor(GB888(0x797979));//阴影框
      ILI9341_DrawLine(0,25,LCD_X_LENGTH,25,2);
      LCD_SetForeColor(GB888(0xCDCDCD));
      ILI9341_DrawLine(0,27,LCD_X_LENGTH,27,1);
      
      LCD_SetForeColor(WHITE);//Wifi设计
      ILI9341_DrawLine(LCD_X_LENGTH-20,19,LCD_X_LENGTH-15,19,3);
      ILI9341_DrawLine(LCD_X_LENGTH-25,12,LCD_X_LENGTH-10,12,3);
      ILI9341_DrawLine(LCD_X_LENGTH-28,5,LCD_X_LENGTH-7,5,3);
      
      
      LCD_SetFont(&Font8x16);
      LCD_SetColors(GB888(0xE8E5C4), GB888(0x589447)); //白色文字，绿色背景
      /********显示字符串示例*******/
      ILI9341_DispStringLine_EN(LINE(0),"Wangqi Telephone:");
      
      LCD_SetFont(&Font8x16);  //制作对话框
      LCD_SetColors( GB888(0x000000), GB888(0xFFC162));
      ILI9341_DispStringLine_EN(LINE(3),"  Personnal News:");
      
      LCD_SetForeColor(GB888(0x589447)); //灰色的框
      ILI9341_DrawRectangle( 10,65,(LCD_X_LENGTH-20),30,0,1);
      LCD_SetForeColor(GB888(0xC3C09C)); //里面的
      ILI9341_DrawRectangle( 11,66,(LCD_X_LENGTH-20-1),30-1,1,1);
      
      
      LCD_SetFont(&Font8x16);
      LCD_SetColors(GB888(0xE8E5C4), GB888(0x589447));
      LCD_SetForeColor(GB888(0x589447)); //绿色的按钮
      ILI9341_DrawRectangle( 180,110,(50),30,1,1);
      LCD_SetForeColor(WHITE); //白色阴影
      ILI9341_DrawRectangle( 180,110,(50),30,0,1);
           
      //-------------------------
      LCD_SetFont(&Font8x16);  //制作对话框
      LCD_SetColors( GB888(0xC90000), GB888(0xFFC162)); //红色文字
      ILI9341_DispStringLine_EN(LINE(9)," Have Girlfriend?");
      //-------------------------
      LCD_SetColors( GB888(0xF0A0A1), GB888(0xFFC162)); //红色文字
      ILI9341_DrawCircle(210,180,10,1,1);
      LCD_SetForeColor(GB888(0x797979));//阴影框
      ILI9341_DrawCircle(210,180,10,0,1);
      LCD_SetColors( GB888(0x34BDD5), GB888(0xFFC162)); //红色文字
      ILI9341_DrawCircle(210,205,10,1,1);
       LCD_SetForeColor(GB888(0x797979));//阴影框
      ILI9341_DrawCircle(210,205,10,0,1);
      //-------------------------
      LCD_SetFont(&Font16x24);  //制作对话框
      LCD_SetColors( GB888(0xBB3756), GB888(0xFFC162)); //红色文字
      ILI9341_DispStringLine_EN(LINE(7),"        Yes!");
      LCD_SetColors( GB888(0x310F29), GB888(0xFFC162)); //红色文字
      ILI9341_DispStringLine_EN(LINE(8),"         NO!");
      
      //-------------------------
      LCD_SetForeColor(GB888(0xA6A6A6));//阴影框
      ILI9341_DrawLine(0,230,LCD_X_LENGTH,230,1);
      
      LCD_SetColors( GB888(0xBF5BBA), GB888(0xFFC162)); //红色文字
      ILI9341_DispStringLine_EN(LINE(10),"   My LOVE ");
       LCD_SetColors(  GB888(0x2369FC) , GB888(0xFFC162)); //白色文字
      ILI9341_DispStringLine_EN(LINE(12)," Hi 2021-8-14 ");
 
}

