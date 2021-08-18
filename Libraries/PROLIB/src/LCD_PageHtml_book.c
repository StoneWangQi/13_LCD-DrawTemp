#include "LCD_PageHtml_book.h" 
 
 
 
/// ��ģ ��� �ֿ� 16 �ָ� 16 
//  ����  ���� 24 24 ˳�� 16����  
//uint8_t test_modu[] ={ 
// 0x00,0x00,0x7F,0xFC,0x01,0x00,0x01,0x00,0x01,0x00,0x01,
// 0x00,0x01,0x00,0x3F,0xF8,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00 ,
// 0x01,0x00,0x01,0x00,0xFF,0xFE,0x00,0x00};/*"��",0*/

//#define _row_count  16
//#define _byte_count  2
//#define _bit_count   8
 
/// ��ģ ��� �ֿ� 32 �ָ� 32 
//  ����  ���� 24 24 ˳�� 16����  
uint8_t test_modu2[] ={ 
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 ,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xC0,0x07,0xFF,0xFF,0xC0 ,
 0x04,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x01,0xFF,0xFF,0x00,0x03,0xFF,0xFF,0x00 ,
 0x03,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x1F,0xFF,0xFC,0x00,0x3F,0xFF,0xFF,0xFE ,
 0x7F,0x80,0x7F,0xFE,0x60,0x00,0x03,0xFC,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 ,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};/*"��",0*/ 

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


//================================ ҳ����ƺ���=======================================

/**
 * @brief  ��ILI9341��ʾ���Ͽ���һ������
 * @param  usX �����ض�ɨ�跽���´��ڵ����X����
 * @param  usY �����ض�ɨ�跽���´��ڵ����Y����
 * @param  usWidth �����ڵĿ��
 * @param  usHeight �����ڵĸ߶�
 * @retval ��
 */
void  fn_Lcd_Page1(void){

//      printf("\n-->LCD %x",GB565(255, 193 ,98));
//      printf("\n-->LCD %x",GB888(0xFFC162));
  
      LCD_SetColors( GB888(0x589447), GB888(0xFFC162));
      ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* ��������ʾ ��ɫ�Ľ��� */
      
      LCD_SetForeColor(GB888(0x589447)); //������ɫ�Ŀ�
      ILI9341_DrawRectangle( 0,0,LCD_X_LENGTH,25,1,1);
      LCD_SetForeColor(GB888(0x797979));//��Ӱ��
      ILI9341_DrawLine(0,25,LCD_X_LENGTH,25,2);
      LCD_SetForeColor(GB888(0xCDCDCD));
      ILI9341_DrawLine(0,27,LCD_X_LENGTH,27,1);
      
      LCD_SetForeColor(WHITE);//Wifi���
      ILI9341_DrawLine(LCD_X_LENGTH-20,19,LCD_X_LENGTH-15,19,3);
      ILI9341_DrawLine(LCD_X_LENGTH-25,12,LCD_X_LENGTH-10,12,3);
      ILI9341_DrawLine(LCD_X_LENGTH-28,5,LCD_X_LENGTH-7,5,3);
      
      
      LCD_SetFont(&Font8x16);
      LCD_SetColors(GB888(0xE8E5C4), GB888(0x589447)); //��ɫ���֣���ɫ����
      /********��ʾ�ַ���ʾ��*******/
      ILI9341_DispStringLine_EN(LINE(0),"Wangqi Telephone:");
      
      LCD_SetFont(&Font8x16);  //�����Ի���
      LCD_SetColors( GB888(0x000000), GB888(0xFFC162));
      ILI9341_DispStringLine_EN(LINE(3),"  Personnal News:");
      
      LCD_SetForeColor(GB888(0x589447)); //��ɫ�Ŀ�
      ILI9341_DrawRectangle( 10,65,(LCD_X_LENGTH-20),30,0,1);
      LCD_SetForeColor(GB888(0xC3C09C)); //�����
      ILI9341_DrawRectangle( 11,66,(LCD_X_LENGTH-20-1),30-1,1,1);
      
      
      LCD_SetFont(&Font8x16);
      LCD_SetColors(GB888(0xE8E5C4), GB888(0x589447));
      LCD_SetForeColor(GB888(0x589447)); //��ɫ�İ�ť
      ILI9341_DrawRectangle( 180,110,(50),30,1,1);
      LCD_SetForeColor(WHITE); //��ɫ��Ӱ
      ILI9341_DrawRectangle( 180,110,(50),30,0,1);
           
      //-------------------------
      LCD_SetFont(&Font8x16);  //�����Ի���
      LCD_SetColors( GB888(0xC90000), GB888(0xFFC162)); //��ɫ����
      ILI9341_DispStringLine_EN(LINE(9)," Have Girlfriend?");
      //-------------------------
      LCD_SetColors( GB888(0xF0A0A1), GB888(0xFFC162)); //��ɫ����
      ILI9341_DrawCircle(210,180,10,1,1);
      LCD_SetForeColor(GB888(0x797979));//��Ӱ��
      ILI9341_DrawCircle(210,180,10,0,1);
      LCD_SetColors( GB888(0x34BDD5), GB888(0xFFC162)); //��ɫ����
      ILI9341_DrawCircle(210,205,10,1,1);
       LCD_SetForeColor(GB888(0x797979));//��Ӱ��
      ILI9341_DrawCircle(210,205,10,0,1);
      //-------------------------
      LCD_SetFont(&Font16x24);  //�����Ի���
      LCD_SetColors( GB888(0xBB3756), GB888(0xFFC162)); //��ɫ����
      ILI9341_DispStringLine_EN(LINE(7),"        Yes!");
      LCD_SetColors( GB888(0x310F29), GB888(0xFFC162)); //��ɫ����
      ILI9341_DispStringLine_EN(LINE(8),"         NO!");
      
      //-------------------------
      LCD_SetForeColor(GB888(0xA6A6A6));//��Ӱ��
      ILI9341_DrawLine(0,230,LCD_X_LENGTH,230,1);
      
      LCD_SetColors( GB888(0xBF5BBA), GB888(0xFFC162)); //��ɫ����
      ILI9341_DispStringLine_EN(LINE(10),"   My LOVE ");
       LCD_SetColors(  GB888(0x2369FC) , GB888(0xFFC162)); //��ɫ����
      ILI9341_DispStringLine_EN(LINE(12)," Hi 2021-8-14 ");
 
}

