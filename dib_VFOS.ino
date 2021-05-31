            
            String  new_qrg_tmp, old_qrg_tmp, dds ;
            String  str_tmp, strf;
            
            
            void dibuja_VFOs()
            {
            
// VFO activo ·······················································
            
            if( ACT_VFO == 0)  // vfoA = 0,  vfoB = 1
            { 
               new_qrg_tmp = String(vfoA_freq);
               old_qrg_tmp = String(old_qrg_vfoA);
            } 
            else {
               new_qrg_tmp = String(vfoB_freq);
               old_qrg_tmp = String(old_qrg_vfoB);
            }
            
// ___________________________________________________________
                
                
                switch (new_qrg_tmp.length())
                {
                    case 5: new_qrg_tmp = "   " + new_qrg_tmp;
                    break;
                    case 6: new_qrg_tmp = "  " + new_qrg_tmp;
                    break;
                    case 7: new_qrg_tmp = " " + new_qrg_tmp;
                    break;
                }
                switch (old_qrg_tmp.length())
                {
                   case 5: old_qrg_tmp = "   " + old_qrg_tmp;
                   break;
                   case 6: old_qrg_tmp = "  " + old_qrg_tmp;
                   break;
                   case 7: old_qrg_tmp = " " + old_qrg_tmp;
                   break;
                }
                
            
                       dds = String(new_qrg_tmp.charAt(7));
                       if( new_qrg_tmp.charAt(7) != old_qrg_tmp.charAt(7)  )
                       {
                          sprite_7.fillRect(0,0,34,52,TFT_BLACK);
                          sprite_7.drawString(dds, 0,0,GFXFF); 
                          sprite_7.pushSprite(282,40);              
                       }
                    
             
                       dds = String(new_qrg_tmp.charAt(6));
                       if( new_qrg_tmp.charAt(6) != old_qrg_tmp.charAt(6) )
                       {
                          sprite_6.fillRect(0,0,34,52,TFT_BLACK);
                          sprite_6.drawString(dds, 0,0,GFXFF);
                          sprite_6.pushSprite(248,40);
                       }
            
                       dds = String(new_qrg_tmp.charAt(5));
                       if( new_qrg_tmp.charAt(5) != old_qrg_tmp.charAt(5) )
                       {
                          sprite_5.fillRect(0,0,34,52,TFT_BLACK); 
                          sprite_5.drawString(dds, 0,0,GFXFF);
                          sprite_5.pushSprite(197,40);
                       }
            
                       dds = String(new_qrg_tmp.charAt(4));
                       if( new_qrg_tmp.charAt(4) != old_qrg_tmp.charAt(4) )
                       {
                          sprite_4.fillRect(0,0,34,52,TFT_BLACK);
                          sprite_4.drawString(dds, 0,0,GFXFF);
                          sprite_4.pushSprite(163,40);
                       }
            
                       dds = String(new_qrg_tmp.charAt(3));
                       if( new_qrg_tmp.charAt(3) != old_qrg_tmp.charAt(3) )
                       {
                          sprite_3.fillRect(0,0,34,52,TFT_BLACK);
                          sprite_3.drawString(dds, 0,0,GFXFF);               
                          sprite_3.pushSprite(129,40);
                       }
            
                       dds = String(new_qrg_tmp.charAt(2));
                       if( new_qrg_tmp.charAt(2) != old_qrg_tmp.charAt(2) )
                       {
                          sprite_2.fillRect(0,0,34,52,TFT_BLACK);
                          sprite_2.drawString(dds, 0,0,GFXFF);                
                          sprite_2.pushSprite(78,40);
                       }
            
                       
                       dds = String(new_qrg_tmp.charAt(1));
                       if( new_qrg_tmp.charAt(1) != old_qrg_tmp.charAt(1) )
                       {
                          sprite_1.fillRect(0,0,34,52,TFT_BLACK);
                          sprite_1.drawString(dds, 0,0,GFXFF); 
                          sprite_1.pushSprite(44,40);
                       }
             
                       dds = String(new_qrg_tmp.charAt(0));
                       if( new_qrg_tmp.charAt(0) != old_qrg_tmp.charAt(0) )
                       {
                          sprite_0.fillRect(0,0,34,52,TFT_BLACK);
                          sprite_0.drawString(dds, 0,0,GFXFF);  
                          sprite_0.pushSprite(10,40);
                       }
            
                       
                       // vfoA = 0,  vfoB = 1
                       if( ACT_VFO == 0)  old_qrg_vfoA = vfoA_freq;
                         else old_qrg_vfoB = vfoB_freq;
            
            
            
// Dibuja el VFO no activo ···················································
            
            
                       if( ACT_VFO == 0)  // vfoA = 0,  vfoB = 1 
                           str_tmp = String(vfoB_freq); else str_tmp = String(vfoA_freq);
                           
                       switch (str_tmp.length()) 
                       {
                          case  5: strf = "    " + str_tmp.substring(0,3) + "." + str_tmp.substring(3);
                          break;             
                          case  6: strf = "  " + str_tmp.substring(0,1) + "." + str_tmp.substring(1,4) + "." + str_tmp.substring(4);
                          break;
                          case  7: strf = " " + str_tmp.substring(0,2) + "." + str_tmp.substring(2,5) + "." + str_tmp.substring(5);             
                          break;
                          case  8: strf = str_tmp.substring(0,3) + "." + str_tmp.substring(3,6) + "." + str_tmp.substring(6);    
                          break;
                        }
                
                        /*tft.setFreeFont(FF53);
                        tft.fillRect(15,245,100,20,TFT_RED);
                        tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
                        tft.setCursor(15,245);
                        tft.print(strf);
                        */
                        
                        sprite_vfob.fillRect(210,0,20,60,TFT_BLACK);   //Borra los restos que quedan de la cadena anterior en el sprite
                        sprite_vfob.drawString(strf, 0, 0, GFXFF);
                        sprite_vfob.pushSprite(15,245);    
                                    
            }
