#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int len = 4; int gtlen;  // Lên là trừ
int xuong = 5; int gtxuong; // Xuống là cộng
int menu = 6; int gtmenu; 
int back = 7; int gtback; 
int macdinh = 1;

int congtru_tong = 0; int congtru_menu1 = 0; int congtru_menu2 = 0;
int demmenu1 = 0; int demmenu2 = 0;
int demtong = 0;  
int demback = 0;

int bientro = A0; int gtbientro; int gtbiendoi;
int gtdosang = 0;

void manhinh()  // HIỂN THỊ MÀN HÌNH CHÍNH
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" MAN HINH CHINH "); 
}

void menu_tong() // HIỂN THỊ MENU TỔNG
{
  if (congtru_tong == 0)
  {
    lcd.clear();
    lcd.print(">MENU 1");
    lcd.setCursor(0, 1);
    lcd.print(" MENU 2");  
  }
  else if (congtru_tong == 1)
  {
    lcd.clear();
    lcd.print(" MENU 1");
    lcd.setCursor(0, 1);
    lcd.print(">MENU 2");    
  }
  else if (congtru_tong == 2)
  {
    lcd.clear();
    lcd.print(">MENU 3");
    lcd.setCursor(0, 1);
    lcd.print(" MENU 4");   
  }
  else if (congtru_tong == 3)
  {
    lcd.clear();
    lcd.print(" MENU 3");
    lcd.setCursor(0, 1);
    lcd.print(">MENU 4");    
  }
}

void chonmenu_tong() // CHỌN MENU TỔNG
{
  switch (congtru_tong) 
  {
    case 0:
      //Không làm gì
      break;
    case 1:
      //Không làm gì
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("MENU 3");
      lcd.setCursor(0,1);
      lcd.print("NOI DUNG MENU 3.");
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("MENU 4");
      lcd.setCursor(0,1);
      lcd.print("NOI DUNG MENU 4.");
      break;
  }
}

void menu_1()  // HIỂN THỊ MENU 1
{
  if (congtru_menu1 == 0)
  {
    lcd.clear();
    lcd.print(">MENU 1-A");
    lcd.setCursor(0, 1);
    lcd.print(" MENU 1-B");  
  }
  else if (congtru_menu1 == 1)
  {
    lcd.clear();
    lcd.print(" MENU 1-A");
    lcd.setCursor(0, 1);
    lcd.print(">MENU 1-B");    
  }
  else if (congtru_menu1 == 2)
  {
    lcd.clear();
    lcd.print(">MENU 1-C");
    lcd.setCursor(0, 1);
    lcd.print(" MENU 1-D");  
  }
  else if (congtru_menu1 == 3)
  {
    lcd.clear();
    lcd.print(" MENU 1-C");
    lcd.setCursor(0, 1);
    lcd.print(">MENU 1-D");    
  }    
}

void chonmenu_1() // CHỌN MENU 1
{
  switch (congtru_menu1) 
  {
    case 0:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("    MENU 1-A    ");
      lcd.setCursor(0,1);
      lcd.print("  NOI DUNG 1-A  ");
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("    MENU 1-B    ");
      lcd.setCursor(0,1);
      lcd.print("  NOI DUNG 1-B  ");
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("    MENU 1-C    ");
      lcd.setCursor(0,1);
      lcd.print("  NOI DUNG 1-C  ");
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("    MENU 1-D    ");
      lcd.setCursor(0,1);
      lcd.print("  NOI DUNG 1-D  ");
      break;      
  }
}

void menu_2() // HIỂN THỊ MENU 2
{
  if (congtru_menu2 == 0)
  {
    lcd.clear();
    lcd.print(">BIEN TRO");
    lcd.setCursor(0, 1);
    lcd.print(" DO SANG");  
  }
  else if (congtru_menu2 == 1)
  {
    lcd.clear();
    lcd.print(" BIEN TRO");
    lcd.setCursor(0, 1);
    lcd.print(">DO SANG");    
  }  
}

void chonmenu_2() // CHỌN MENU 2
{
  switch (congtru_menu2) 
  {
    case 0:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("   BIEN TRO   ");
      lcd.setCursor(0,1);
      lcd.print("GIA TRI: ");
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("    DO SANG   ");
      lcd.setCursor(0,1);
      lcd.print("GIA TRI: ");     
      break;
  }
}

void setup() 
{
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
  
  pinMode(len, INPUT_PULLUP);
  pinMode(xuong, INPUT_PULLUP);
  pinMode(menu, INPUT_PULLUP);
  pinMode(back, INPUT_PULLUP);

  pinMode(bientro, INPUT);
  
  manhinh();
}

void loop() 
{
  gtbientro = analogRead(bientro);  
  gtbiendoi = map(gtbientro, 0, 1023, 0, 100);
  //Serial.print("Biến trở: "); Serial.print(gtbientro); Serial.print("    ");

  gtlen = digitalRead(len);  
  gtxuong = digitalRead(xuong);  
  gtmenu = digitalRead(menu);
  gtback = digitalRead(back);
  // Serial.print("LÊN: "); Serial.print(gtlen); Serial.print("    ");
  // Serial.print("XUỐNG: "); Serial.print(gtxuong); Serial.print("    ");
  // Serial.print("Menu: "); Serial.print(gtmenu); Serial.print("    ");
  // Serial.print("Back: "); Serial.print(gtback); Serial.print("    "); 

if (gtlen != macdinh)  // NÚT LÊN
{
  if (gtlen == 0) // Khi nhấn nút lên
  {
    if (demtong == 1)   // LÊN Ở MENU TỔNG  
    {
      if (congtru_tong >= 3)
      { 
        congtru_tong= 0;  
      }
      else
      { 
        congtru_tong++;  
      }   
      menu_tong();
    }
    
    else if (demtong == 2 && congtru_tong == 0)   // LÊN Ở MENU 1
    {
      if (congtru_menu1 >= 3)
      { 
        congtru_menu1 = 0;  
      }
      else
      { 
        congtru_menu1++;  
      }   
      menu_1();
    }
    
    else if (demtong == 2 && congtru_tong == 1)   // LÊN Ở MENU 2
    {
      if (congtru_menu2 >= 1)
      { 
        congtru_menu2 = 0;  
      }
      else
      { 
        congtru_menu2++;  
      }   
      menu_2();
    }

    else if (demtong == 3 && demmenu2 == 1)   // - ĐỘ SÁNG
    {
      if (gtdosang <= 0)
      { 
        gtdosang = 0;  
      }
      else
      { 
        gtdosang--;  
      }
    }  

    delay(200);
  }
  macdinh = gtlen;
}

if (gtxuong != macdinh) // NÚT XUỐNG
{
  if (gtxuong == 0) //Khi nhấn nút xuống
  {
    if (demtong == 1)   // XUỐNG Ở MENU TỔNG
    {
      if (congtru_tong <= 0)
      { 
        congtru_tong = 3;  
      }
      else
      { 
        congtru_tong--;  
      }
      menu_tong();
    }
    
    else if (demtong == 2 && congtru_tong == 0)   // XUỐNG Ở MENU 1
    {
      if (congtru_menu1 <= 0)
      { 
        congtru_menu1 = 3;  
      }
      else
      { 
        congtru_menu1--;  
      }
      menu_1();
    }
    
    else if (demtong == 2 && congtru_tong == 1)   // XUỐNG Ở MENU 2
    {
      if (congtru_menu2 <= 0)
      { 
        congtru_menu2 = 1;  
      }
      else
      { 
        congtru_menu2--;  
      }
      menu_2();
    }

    else if (demtong == 3 && demmenu2 == 1)   // + ĐỘ SÁNG
    {
      if (gtdosang >= 100)
      { 
        gtdosang = 100;  
      }
      else
      { 
        gtdosang++;  
      }
    }  

    delay(200);
  }
  macdinh = gtxuong;
}

if (gtmenu != macdinh)    // NÚT MENU
{  
  if (gtmenu == 0) //Khi nhấn nút
  {  
    demtong ++;
    if (demtong == 1) //Ở menu tổng
    { 
      demback = 0;
      menu_tong(); 
    }

    else if (demtong == 2 && congtru_tong == 0) //ở menu 1
    {
      demback = 0;
      menu_1(); 
      demmenu1++;
    }
      else if (demtong == 3 && demmenu1 == 1) // Chọn menu_1
      {
        demback = 0;
        chonmenu_1();
      }

    else if (demtong == 2 && congtru_tong == 1) //Ở menu 2
    {
      demback = 0;
      menu_2(); 
      demmenu2++;
    }
      else if (demtong == 3 && demmenu2 == 1) // Chọn menu_2
      {
        demback = 0;
        chonmenu_2();
      }

    else if (demtong == 2 && (congtru_tong == 2 or congtru_tong == 3)) // chọn menu tổng 3 or 4
    {
      demback = 0;
      chonmenu_tong();
    }
      else if (demtong == 3 && (congtru_tong == 2 or congtru_tong == 3)) // Đang chọn menu 3 or 4 nhưng nhấn nút menu lên 3
      {
        demback = 0;
        demtong = 2;
        chonmenu_tong();
      }    

    else if (demtong > 3)
    {
      demtong = 3;
      demback = 0;
    }

    delay(100);
  }
  macdinh = gtmenu;
}

if (gtback != macdinh)    // NÚT BACK
{  
  if (gtback == 0) // Khi nhấn nút
  {
    demback ++;
    if (demback == 1)
    {
      if (demtong == 1 && (congtru_tong == 0 or congtru_tong == 1 
                            or congtru_tong == 2 or congtru_tong == 3)) // TỪ MENU TỔNG TRỞ VỀ MÀN HÌNH
      {
        demtong = demtong - 1;
        demback = 0;
        manhinh();
      }
      else if (demtong == 2 && congtru_tong == 0) // TỪ MENU 1 TRỞ VỀ MENU TỔNG
      {
        demtong = demtong - 1;
        demback = 0;
        demmenu1 = 0;
        menu_tong();
      }
      else if (demtong == 2 && congtru_tong == 1) // TỪ MENU 2 VỀ MENU TỔNG
      {
        demtong = demtong - 1;
        congtru_tong = congtru_tong - 1; 
        congtru_menu2 = 0;
        demmenu2 = 0;
        demback = 0;
        menu_tong(); 
      }
      else if (demtong == 2 && (congtru_tong == 2 or congtru_tong == 3)) // TỬ MENU 3 OR 4 THOÁT RA MENU TỔNG
      {
        demback = 0;
        demtong = demtong - 1;
        congtru_tong = 0;
        menu_tong();
      }
      else if (demtong == 3 && demmenu1 >= 1) // TỪ CHỌN-MENU 1 VỀ MENU 1
      {
        demback = 0;
        demtong = 2;
        congtru_menu1 = 0;
        menu_1();
      } 
      else if (demtong == 3 && demmenu2 >= 1) // TỪ CHỌN-MENU 2 VỀ MENU 2
      {
        demback = 0;
        demtong = 2;
        congtru_menu2 = 0;
        menu_2();
      }      
    }

    else
    {
      demback = 0;
    }
    delay(100);
  }
  macdinh = gtback;
}

  if (demtong == 3 && demmenu2 == 1) //CHỌN MENU 2: biến trở và độ sáng
  {
      if (congtru_menu2 == 0)  //Biến trở
        {
          if (gtbiendoi < 10)
          {
            lcd.setCursor(9,1);
            lcd.print(gtbiendoi);
            lcd.setCursor(10,1);
            lcd.print("      ");
          }
          else if (gtbiendoi < 100)
          {
            lcd.setCursor(9,1);
            lcd.print(gtbiendoi);
            lcd.setCursor(11,1);
            lcd.print("     ");
          }
          else
          {
            lcd.setCursor(9,1);
            lcd.print(gtbiendoi);
            lcd.setCursor(12,1);
            lcd.print("    ");
          }
        }

      else if (congtru_menu2 == 1) // Độ sáng
        {
          if (gtdosang < 10)
          {
            lcd.setCursor(9,1);
            lcd.print(gtdosang);
            lcd.setCursor(10,1);
            lcd.print("      ");
          }
          else if (gtdosang < 100)
          {
            lcd.setCursor(9,1);
            lcd.print(gtdosang);
            lcd.setCursor(11,1);
            lcd.print("     ");
          }
          else
          {
            lcd.setCursor(9,1);
            lcd.print(gtdosang);
            lcd.setCursor(12,1);
            lcd.print("    ");
          }  
        }  
  }

  Serial.print("Đếm tổng: "); Serial.print(demtong); Serial.print("    ");
  Serial.print("+/- tổng: "); Serial.print(congtru_tong); Serial.print("    ");
  Serial.print("Đếm menu 1 : "); Serial.print(demmenu1); Serial.print("    ");
  Serial.print("Đếm menu 2 : "); Serial.print(demmenu2); Serial.print("    ");
  Serial.print("+/- menu 1: "); Serial.print(congtru_menu1); Serial.print("    ");
  Serial.print("+/- menu 2: "); Serial.print(congtru_menu2); Serial.print("    ");
  Serial.print("Đếm back: "); Serial.print(demback); Serial.println("    ");

} //Kết loop
