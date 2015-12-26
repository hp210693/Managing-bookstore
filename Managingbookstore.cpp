#include <iostream.h>
using namespace std;
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream>
struct sach
{
    int ma_sach;
    string ten_sach;
    float gia_ban;
    string tac_gia;
    string nxb;
    int nam_xb;
    sach *pre;
    sach *pnext;
};
struct list_sach
{
    sach *phead;
    sach *ptail;
};
struct gia_sach
{
    int ma_gia;
    string ten_gia;
    string khu_vuc;
    list_sach ls;
    gia_sach *pnext;
};
struct list_gia
{
    gia_sach *phead;
    gia_sach *ptail;
};
void  menu();
void menusach(sach *p);
void menugiasach(gia_sach *gs);
void Init(list_gia &lg);
void Init(list_sach &ls);
gia_sach nhap_gia(list_gia lg);
bool KiemTraMa_Sach(list_sach ls,int ma_sach);
sach nhap_sach(list_gia lg);
sach*tao_sach(int ma_sach,string ten_sach,float gia_ban,string tac_gia,string nxb,int nam_xb);
gia_sach*tao_gia(int ma_gia,string ten_gia,string khu_vuc);
void add_sach(list_sach &ls,sach *new_sach);
void add_gia(list_gia &lg,gia_sach*new_gia);
void xuat_dsgia(list_gia lg);
void xuat_dssach(list_sach ls);
sach*search_sach(list_gia lg,int ma_sach);
gia_sach*search_gia(list_gia lg,int ma_gia);
void xoa_sach(list_gia &lg,int ma_sach);
void xoa_sach_trong_gia(list_sach &ls);
void xoa_gia(list_gia &lg,int ma_gia);
void xoa_het_gia(list_gia &lg);
void xoa_het_sach(list_gia &lg,int ma_gia);
void hoanvigia(gia_sach *p,gia_sach *q);
void sap_xep_gia(list_gia &lg);
void hoanvisach(list_sach &ls);
void sap_xep_sach(list_gia &lg,int ma_gia);
void intoanbosach(list_gia lg);
void sua_thongtin_gia(list_gia &lg,int ma_gia);
void sua_thongtin_sach(list_gia &lg,int ma_sach);
sach *picknode(list_sach &ls);
void chuyen_sach(list_gia &lg,int ma_gia1,int ma_gia2);
void luu_file(list_gia &lg,fstream &ghi);
void doc_file(list_gia &lg);
int dem_gia(list_gia &lg);
int dem_sach(list_sach &ls);
int main()
{ 

	 
    list_gia lg;
    Init(lg);//khoi tao gia sach rong
    int ans;
    do
    {
        system("cls");//xoa man hinh
        menu();
        cout<<"Nhap lua chon--> ";
        cin>>ans;
        switch(ans)
        {
         	 case 1:
         	 {
 	        	    gia_sach gs,*new_gia;
		            gs=nhap_gia(lg);
		            new_gia=tao_gia(gs.ma_gia,gs.ten_gia,gs.khu_vuc);//tao gia moi
		            add_gia(lg,new_gia);
		            cout<<"...successful !\n\n";
	     	 	    break; 
 	        }
      	    case  2:
      	    {
    	      		sach s,*new_sach,*new_sach2;
		            s=nhap_sach(lg);
		            new_sach=tao_sach(s.ma_sach,s.ten_sach,s.gia_ban,s.tac_gia,s.nxb,s.nam_xb);//tao 1 cuon sach moi
		            if(lg.ptail==NULL)
		            {
		            	cout<<"Gia sach dang rong vui long tao gia sach nhan ENTER de tiep tuc!!!\n";
		            	getch();
		            	system("cls");
		            	menu();
		                cout<<"Nhap lua chon--> 2\n";
            			gia_sach gs,*new_gia;
			            gs=nhap_gia(lg);
			            new_gia=tao_gia(gs.ma_gia,gs.ten_gia,gs.khu_vuc);//tao gia moi
			            add_gia(lg,new_gia);
			            getch();
            		}
            	    int ma_gia;
		            cout<<"nhap ma gia de sach : ";
		            cin>>ma_gia;
                    gia_sach *p=lg.phead;// p tro toi dau gia sach
    	           	while(p!=NULL)
	       		    {
			       		if(p->ma_gia==ma_gia)
     				    {
						   add_sach(p->ls,new_sach); //them sach vao gia sach
						   break;
					    }
					    else
				    	{
          					p=p->pnext;   
	    					if(p==NULL)//neu gia sach tro den null (tro sau ptail)
	    					{
					    		cout<<"Ma gia sach khong ton tai vui long nhap gia khac nhan ENTER de tiep tuc !!!\n";
					    		getch();
							    system("cls");
				                menu();
			                    cout<<"Nhap lua chon--> 2\n";
				                p=lg.phead;//p tro lai dau gia sach duyet lai tu dau
					    		cout<<"nhap ma gia de sach : ";
		         			    cin>>ma_gia;
		         			    continue;
					    	}
	    				}     
    	            }
		           cout<<"...successful !\n";
		           break;
   	        }
       		case 3:
		            xuat_dsgia(lg);//xuat danh sach cac gia sach
		            break;
	        case 4:
		            int ma_gia;
		            cout<<"Chon gia de sach: ";
		            cin>>ma_gia;
		            if(lg.ptail==NULL)//gia sach rong
		            	cout<<"Gia sach nay khong ton tai !!!\n";
	            	else
	            	{
           		 		gia_sach *p=lg.phead;//p tro toi dau gia sach
            		 	while(p!=NULL)
           				{
				             if(p->ma_gia==ma_gia)
				             {
				             	xuat_dssach(p->ls);//xuat cac cuon sach trong gia sach
				             	break;
             			   	 }
             				 else
             				 {
       				 	    	 p=p->pnext;
 				             	  if(p==NULL)
 	             				 		cout<<"Gia sach nay khong ton tai !!!\n";
 				             }
            		 	}
	            	}  
		            break;
	        case 5:
	            int ma_sach;
	            cout<<"nhap ma sach can tim: ";
	            cin>>ma_sach;
	            if(search_sach(lg,ma_sach))//tim sach theo ma_sach
	            {
	                sach *p=search_sach(lg,ma_sach);
                 	cout<<"\t\t\t\tTIM SACH THEO MA SACH\n";
	              	menusach(p);
	            }
	            else
	                cout<<"Khong tim thay sach !!!\n";
	            break;
	        case 6:
         	{
        		int ma_gia;
	            cout<<"nhap ma gia can tim: ";
	            cin>>ma_gia;
	            if(search_gia(lg,ma_gia))//tim gia_sach theo ma_gia
	            {
	                gia_sach *p=search_gia(lg,ma_gia);
                 	cout<<"\t\tTIM GIA SACH THEO MA GIA\n";
	                menugiasach(p);
	            }
	            else
	                cout<<"Khong tim thay gia sach!!!\n";
	            break;
         	}
	        case 7:
	        {
        			int ma_sach;
		            cout<<"nhap ma sach can xoa: ";
		            cin>>ma_sach;
	             	sach *p=search_sach(lg,ma_sach);
		            if(p!=NULL)//tim sach trong gia sach
		            {
		            	cout<<"\t\t\t\tXOA SACH THEO MA SACH\n";
		                menusach(p);
		                cout<<"deleting...\n";
		                xoa_sach(lg,ma_sach);
		                cout<<"sucessfull...\n";
		            }
		            else
	            		cout<<"Khong tim thay sach !!!\n";    
		            break;	
        	}
	        case 8:
	        {
        			int ma_gia;
        		 	cout<<"nhap ma gia can xoa: ";
	            	cin>>ma_gia;
            		gia_sach *p=search_gia(lg,ma_gia);
	            	if(p!=NULL)
	            	{
	            		cout<<"\t\tXOA GIA THEO MA GIA\n";
	                	menugiasach(p);
	                	xoa_gia(lg,ma_gia);
	                	cout<<"sucessfull...\n";
	            	}
	            	else
	                	cout<<"khong tim thay gia !\n";
	            break;	
        	}
	        case 9:
	            cout<<"-------XOA TAT CA GIA-------\n";
	            cout<<"deleting...\n";
	            xoa_het_gia(lg);
	            cout<<"sucessfull...\n";
	            break;
	        case 10:
	        {
	            int ma_gia;
	            cout<<"Nhap ma gia muon xoa sach: ";
	            cin>>ma_gia;
	            gia_sach *p=search_gia(lg,ma_gia);
	            if(p!=NULL)
	            {
					cout<<"deleting...\n";
		            xoa_het_sach(lg,ma_gia);
		            cout<<"successful...\n";	
            	}
				else
	            	cout<<"Ma gia khong ton tai !!!\n";
	            break;
        	}
	            
	        case 11:
	            cout<<"-------SAP XEP DANH SACH GIA-------\n";
	            cout<<"sorting...\n";
	            sap_xep_gia(lg);
	            cout<<"finish !\n";
	            break;
         	case 12:
         	{
	         	int ma_gia;
         		cout<<"-------SAP XEP SACH TREN GIA-------\n";
         		cout<<"Nhap ma gia muon sap xep: ";
         		cin>>ma_gia;
         		gia_sach *p=search_gia(lg,ma_gia);
         		if(p!=NULL)
         		{
		         	cout<<"sorting...\n";
		            sap_xep_sach(lg,ma_gia);
		            cout<<"finish !\n";
	         	}
	            else
	            	cout<<"Ma gia khong ton tai !!!\n";
				break;	
         	}
         	case 13:
         	{
         		intoanbosach(lg);
        		break;
    		}
    		case 14:
    		{
		    	int ma_gia;
		    	cout<<"Nhap ma gia sach can sua: ";
		    	cin>>ma_gia;
		    	gia_sach *p=search_gia(lg,ma_gia);
		    	if(p!=NULL)
		    	{
	    			sua_thongtin_gia(lg,ma_gia);
    			 	cout<<"update complete !\n";
	    		}
	    		else
	    			cout<<"Ma gia nay khong ton tai !!!\n";
    			break;
		    }
		    case 15:
		    {
		    	int ma_sach;
		    	cout<<"Nhap ma sach can sua: ";
		    	cin>>ma_sach;
		    	sach *p=search_sach(lg,ma_sach);
		    	if(p!=NULL)
		    	{
		    		sua_thongtin_sach(lg,ma_sach);
	    			cout<<"updated complete !\n";
	    		}
	    		else
	    			cout<<"Ma sach nay khong ton tai !!!\n";
    			break;
    		}
    		case 16:
    		{
		    	int ma_gia1;
		    	cout<<"Nhap ma gia sach can chuyen: ";
		    	cin>>ma_gia1;
		    	gia_sach *p=search_gia(lg,ma_gia1);
		    	if(p!=NULL)
		    	{
		    		int ma_gia2;
	    			cout<<"Nhap ma gia sach muon nhan: ";
	    			cin>>ma_gia2;
	    			p=search_gia(lg,ma_gia2);
	    			if(p!=NULL&&(ma_gia1!=ma_gia2))
	    			{
			    		chuyen_sach(lg,ma_gia1,ma_gia2);
						cout<<"converted complete !\n";		
			    	}
			    	else
			    		cout<<"Ma gia sach muon nhan khong ton tai hoac bi trung voi ma gia sach can chuyen !!!\n";
	    		}
	    		else
	    			cout<<"Ma gia sach can chuyen khong ton tai !!!\n";
		    	break;
		    }
	        case 17:
			{
				fstream ghi;
				cout<<"-------LUU FILE-------\n";
				cout<<"Saving...\n";
				luu_file(lg,ghi);
				cout<<"finish...\n";
				break;
			}
			case 18:
			{
			
				cout<<"-------DOC FILE-------\n";
				cout<<"Opening...\n";
				doc_file(lg);
				cout<<"\nPress any key to continue";
				break;
			}
			case 19:
			{
				cout<<"Goodbye !!!\n";
				break;
			}
        }
        getch();
    }while(ans!=19);
}
void  menu()
{
	cout<<"\n\t\t\t   CHUONG TRINH QUAN LY KHO SACH\n";
    cout<<"\t\t===================****MENU****===================\n";
    cout<<"\t\t= 1.Tao gia sach\t\t\t\t =\n";
    cout<<"\t\t= 2.Tao sach\t\t\t\t\t =\n";
    cout<<"\t\t= 3.Xuat danh sach gia sach\t\t\t =\n";
    cout<<"\t\t= 4.Xuat danh sach cac cuon sach theo gia sach   =\n";
    cout<<"\t\t= 5.Tim sach theo ma sach\t\t\t =\n";
    cout<<"\t\t= 6.Tim gia sach theo ma gia\t\t\t =\n";
    cout<<"\t\t= 7.Xoa sach theo ma sach\t\t\t =\n";
    cout<<"\t\t= 8.Xoa gia theo ma gia\t\t\t\t =\n";
    cout<<"\t\t= 9.Xoa tat ca gia\t\t\t\t =\n";
    cout<<"\t\t= 10.Xoa tat ca sach theo ma gia\t\t =\n";
    cout<<"\t\t= 11.Sap xep gia sach\t\t\t\t =\n";
    cout<<"\t\t= 12.Sap xep sach theo ma gia\t\t\t =\n";
    cout<<"\t\t= 13.In toan bo sach\t\t\t\t =\n";
   	cout<<"\t\t= 14.Sua thong tin gia sach theo ma gia\t\t =\n";
   	cout<<"\t\t= 15.Sua thong tin sach theo ma sach\t\t =\n";
   	cout<<"\t\t= 16.Chuyen sach sang khu vuc khac\t\t =\n";
   	cout<<"\t\t= 17.Luu file\t\t\t\t\t =\n";
	cout<<"\t\t= 18.Doc file\t\t\t\t\t =\n";
	cout<<"\t\t= 19.Thoat chuong trinh\t\t\t\t =\n";
    cout<<"\t\t==================================================\n";
}
void menusach(sach *p)
{
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<" STT "<<"| "<<" MA SACH "<<" | "<<"  TEN SACH  "<<" | "<<" GIA BAN "<<"| ";
	cout<<"   TAC GIA   "<<" | "<<"  NXB  "<<" | "<<"NAM XB"<<" | ";
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<"  "<<1<<"  |"<<setw(10)<<p->ma_sach<<" | "<<setw(12)<<p->ten_sach<<" | "<<setw(8)<<p->gia_ban;
	cout<<" | "<<setw(13)<<p->tac_gia<<" | "<<setw(7)<<p->nxb<<" | "<<setw(6)<<p->nam_xb<<" | ";
 	cout<<"-------------------------------------------------------------------------------\n";
}
void menugiasach(gia_sach *p)
{
	cout<<"------------------------------------------------------"<<endl;
    cout<<" STT "<<"| "<<"   MA GIA   "<<" | "<<"    TEN GIA    "<<" | "<<"   KHU VUC   "<<"| "<<endl;
    cout<<"------------------------------------------------------"<<endl;
   	cout<<"  "<<1<<"  |"<<setw(13)<<p->ma_gia<<" | "<<setw(15)<<p->ten_gia<<" | "<<setw(12)<<p->khu_vuc<<" | "<<endl;
    cout<<"------------------------------------------------------"<<endl;
}
void Init(list_gia &lg)
{
    lg.phead=lg.ptail=NULL;
    return ;
}
void Init(list_sach &ls)
{
	ls.phead=ls.ptail=NULL;
	return;
}
gia_sach nhap_gia(list_gia lg)
{
    cout<<"-------TAO GIA SACH-------\n";
    gia_sach *p,gs;
    if(lg.ptail==NULL)//danh sach dang rong
    {
        cout<<"MA GIA: ";
        cin>>gs.ma_gia;
        fflush(stdin);
    }
    else
    {
    	p=lg.phead;//p tro toi dau gia sach
    	cout<<"MA GIA: ";
        cin>>gs.ma_gia;
        fflush(stdin);
        while(p!=NULL)//danh sach khac null tiep tuc kiem tra
        {
            if(gs.ma_gia==p->ma_gia)//neu bang thi thuc hien nhap ma_gia khac
            {
                cout<<"Gia sach nay da ton tai vui long nhap gia khac !!!\n";
              	getch();
			    system("cls");
                menu();
      		    cout<<"Nhap lua chon--> 1\n";
      		    cout<<"-------TAO GIA SACH-------\n";
		    	p=lg.phead;//cho p tro lai dau gia sach 
		    	cout<<"MA GIA: ";
		        cin>>gs.ma_gia;
		        fflush(stdin);
                continue;
            }
            p=p->pnext;
        }
    }
    cout<<"TEN GIA: ";
    getline(cin,gs.ten_gia);
    cout<<"KHU VUC: ";
    getline(cin,gs.khu_vuc);
    cout<<"creating...\n";
    return gs;
}
bool KiemTraMa_Sach(list_sach ls,int ma_sach)
{
	sach *s=ls.phead;
	if(ls.ptail==NULL)//danh sach rong
		return false;
	while(s!=NULL)
	{
		if(s->ma_sach==ma_sach)//ton tai ma_sach tra ve true
			return true;
		s=s->pnext;	
	}
	return false;
}
sach nhap_sach(list_gia lg)
{
    sach s;
    cout<<"-------TAO SACH-------\n";
    if(lg.ptail==NULL)
    {
  	 	cout<<"MA SACH: ";
		cin>>s.ma_sach;
	 	fflush(stdin);
    }
    else
    {	
    	gia_sach *gs=lg.phead;//tro toi dau gia sach
    	cout<<"MA SACH: ";
   		cin>>s.ma_sach;
	 	fflush(stdin);
		while(gs!=NULL)
		{
   		 	bool kt;
   		 	kt=KiemTraMa_Sach(gs->ls,s.ma_sach);
 			gs=gs->pnext;//tro qua khoi ke tiep
   		 	if(kt==true)//sach da ton tai tra ve true
   		 	{
	 		   cout<<"Ma sach da ton tai vui long nhap ma khac nhan ENTER de tiep tuc !!!\n";
		       getch();
			   system("cls");
			   menu();
			   cout<<"Nhap lua chon--> 2\n";
    		   cout<<"-------TAO SACH-------\n";
    		   cout<<"MA SACH: ";
   			   cin>>s.ma_sach;
	 		   fflush(stdin);
	 		   gs=lg.phead;
 		    }
		}
    }
    cout<<"TEN SACH: ";
    getline(cin,s.ten_sach);
    fflush(stdin);
    cout<<"GIA BAN: ";
    cin>>s.gia_ban;
    fflush(stdin);
    cout<<"TAC GIA: ";
    getline(cin,s.tac_gia);
    cout<<"NHA XUAT BAN: ";
    getline(cin,s.nxb);
    fflush(stdin);
    cout<<"NAM XUAT BAN: ";
    cin>>s.nam_xb;
    cout<<"creating...\n";
    return s;
}
sach *tao_sach(int ma_sach,string ten_sach,float gia_ban,string tac_gia,string nxb,int nam_xb)
{
    sach *p=new sach;//xin cap phat vung nho
    if(p==NULL)
        return NULL;//neu khong du bo nho
    p->ma_sach=ma_sach;
    p->ten_sach=ten_sach;
    p->gia_ban=gia_ban;
    p->tac_gia=tac_gia;
    p->nxb=nxb;
    p->nam_xb=nam_xb;
    p->pre=p->pnext=NULL;
    return p;
}
gia_sach *tao_gia(int ma_gia,string ten_gia,string khu_vuc)
{
    gia_sach *p=new gia_sach;
    if(p==NULL)return NULL;
    p->ma_gia=ma_gia;
    p->ten_gia=ten_gia;
    p->khu_vuc=khu_vuc;
    p->ls.phead=p->ls.ptail=NULL;
    p->pnext=NULL;
    return p;
}
void add_sach(list_sach &ls,sach *new_sach)
{
    if(ls.ptail==NULL)//danh sach dang rong
        ls.phead=ls.ptail=new_sach;
    else
    {
        ls.ptail->pnext=new_sach;
        new_sach->pre=ls.ptail;
        ls.ptail=new_sach;
    }
}
void add_gia(list_gia &lg,gia_sach*new_gia)
{
    if(lg.phead==NULL)//gia sach rong
    {
        lg.phead=lg.ptail=new_gia;
    }
    else
    {
        lg.ptail->pnext=new_gia;//chen cuoi gia sach
        lg.ptail=new_gia;
    }
}
void xuat_dsgia(list_gia lg)
{
    gia_sach*p=lg.phead;//p tro toi dau gia sach
    int stt=1;
    if(p==NULL)
    {
        cout<<"Gia sach dang rong !!!\n";
        return;
    }
    cout<<"\t\t "<<"DANH MUC GIA SACH\n";
    cout<<"------------------------------------------------------"<<endl;
    cout<<" STT "<<"| "<<"   MA GIA   "<<" | "<<"    TEN GIA    "<<" | "<<"   KHU VUC   "<<"| "<<endl;
    while(p!=NULL)
    {
        cout<<"------------------------------------------------------"<<endl;
        cout<<"  "<<stt<<"  |"<<setw(13)<<p->ma_gia<<" | "<<setw(15)<<p->ten_gia<<" | "<<setw(12)<<p->khu_vuc<<" | "<<endl;
        stt++;
        p=p->pnext;
    }
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Trong kho co: "<<(stt-1)<<" gia sach.\n";
}
void xuat_dssach(list_sach ls)
{
    int stt=1;
    if(ls.ptail==NULL)
    {
        cout<<"Khong co cuon sach nao trong gia nay !!!\n";
        return ;
    }
    sach *p=ls.phead;
    cout<<"\t\t\t\tTIM DANH SACH TREN GIA\n";
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<" STT "<<"| "<<" MA SACH "<<" | "<<"  TEN SACH  "<<" | "<<" GIA BAN "<<"| ";
    cout<<"   TAC GIA   "<<" | "<<"  NXB  "<<" | "<<"NAM XB"<<" | ";
    while(p!=NULL)
    {
        cout<<"-------------------------------------------------------------------------------\n";
        cout<<"  "<<stt<<"  |"<<setw(10)<<p->ma_sach<<" | "<<setw(12)<<p->ten_sach<<" | "<<setw(8)<<p->gia_ban;
        cout<<" | "<<setw(13)<<p->tac_gia<<" | "<<setw(7)<<p->nxb<<" | "<<setw(6)<<p->nam_xb<<" | ";
        stt++;
        p=p->pnext;
    }
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"Gia sach nay co: "<<(stt-1)<<" cuon sach.\n";
}
sach *search_sach(list_gia lg,int ma_sach)//tim lan luot tren tung gia
{
    gia_sach *g=lg.phead;//tro toi dau gia sach
    while(g!=NULL)
    {
        sach *s=g->ls.phead;//khoi tao lai 
        while(s!=NULL)
        {
            if(s->ma_sach==ma_sach)
                return s;
            s=s->pnext;
        }
        g=g->pnext;
    }
    return NULL;
}
gia_sach *search_gia(list_gia lg,int ma_gia)
{
    gia_sach *g=lg.phead;
    while(g!=NULL)
    {
        if(g->ma_gia==ma_gia)
            return g;
        g=g->pnext;
    }
    return NULL;
}
void xoa_sach(list_gia &lg,int ma_sach)
{

    gia_sach *g=lg.phead;//g tro toi dau gia sach
    if(lg.ptail==NULL)//gia sach rong
    {
    	Init(lg);//khoi tao gia sach ve rong
    	return;	
    }
    while(g!=NULL)//gia sach khac rong
    {
        sach *s=g->ls.phead;//tro toi dau list_sach (cua tung gia_sach) khoi dong lai
        if(s==NULL)//khong co cuon sach nao
			return;
        while(s!=NULL)
        {
            if(s->ma_sach==ma_sach)
            {
       			if(s==g->ls.phead)//neu la phan tu dau 
       			{
       				if(s->pnext==NULL)//danh sach chi co 1 phan tu
       				{
				       	delete s;
						g->ls.phead=g->ls.ptail=NULL;
						return;	
			        }
			        g->ls.phead=s->pnext;//dich con tro dau qua phan tu ke
			    	(s->pnext)->pre=NULL;
			    	s->pnext=NULL;
			    	delete s;
			    	return;
	       		}
	       		if(s==g->ls.ptail)
	       		{
		       		g->ls.ptail=s->pre;
		       		s->pre->pnext=NULL;
		       		delete s;
		       		return;
		       	}//khac vi tri dau va cuoi
		        s->pre->pnext=s->pnext;
				(s->pnext)->pre=s->pre;
				delete s;
				return;
            }
            s=s->pnext;//tro qua cuon sach ke tiep
        }
        g=g->pnext;//tro qua gia sach khac
    }
    return ;
}
void xoa_sach_trong_gia(list_sach &ls)
{
	if(ls.ptail==NULL)//list_sach rong
	{
		Init(ls);
		return;
	}
	while(ls.phead!=NULL)
	{
		sach *s=ls.phead;
		ls.phead=s->pnext;
		if(s->pnext==NULL)//phan tu sau la rong
		{
			delete s;
			Init(ls);
			return;
		}
		(s->pnext)->pre=NULL;
		s->pnext=NULL;
		delete s;
	}
	Init(ls);//khoi tao list_sach rong
	return;
}
void xoa_gia(list_gia &lg,int ma_gia)
{
    gia_sach *g=lg.phead;//tro toi dau gia sach
    if(g==NULL)//chua co gia sach nao
    {
    	Init(lg);
 	  	return;	
    }
    while(g!=NULL)
    {
        if(g->ma_gia==ma_gia)
        {
        	if(g==lg.phead)
       		 {
       		 	xoa_sach_trong_gia(g->ls);
	        	if(lg.ptail==lg.phead)//chi co 1 gia_sach
	        	{
	        		Init(lg);
		        	delete g;
		        	return;
		        }//co nhieu hon 1 gia_sach
	        	lg.phead=g->pnext;
	        	g->pnext=NULL;
	        	delete g;
	        	return;
       		 }
	        if(g==lg.ptail)
	        {
	        	xoa_sach_trong_gia(g->ls);
	        	gia_sach *gc=lg.phead;
	        	while(gc->pnext!=lg.ptail)
	        	{
		        	gc=gc->pnext;
		        }//thoat kho vong lap gc truoc phan tu cuoi
		        lg.ptail=gc;
		        gc->pnext=NULL;
		        delete g;
		        return;
	        }//khac vi tri dau cuoi
	        gia_sach *gc=lg.phead;
        	while(gc->pnext!=g)
        	{
		        	gc=gc->pnext;
	        }//thoat kho vong lap gc truoc g
	        xoa_sach_trong_gia(g->ls);
        	gc->pnext=g->pnext;
        	g->pnext=NULL;
        	delete g;
        	return;
        }
        g=g->pnext;
    }
}
void xoa_het_gia(list_gia &lg)
{
    gia_sach *g=lg.phead;
    if(g==NULL)
	{	
		Init(lg);
		return;
	}
    while(g!=NULL)
    {
    	xoa_sach_trong_gia(g->ls);
        gia_sach *p=g;
        g=g->pnext;
        delete p;
    }
    Init(lg);
    //lg.phead=NULL;
    return;
}
void xoa_het_sach(list_gia &lg,int ma_gia)
{
    gia_sach *g=lg.phead;
    if(g==NULL)return;
    while(g!=NULL)
    {
        if(g->ma_gia==ma_gia)
        {
            xoa_sach_trong_gia(g->ls);//xoa toan bo sach
            return;
        }
        g=g->pnext;
    }
}
void hoanvigia(gia_sach *p,gia_sach *q)
{
	gia_sach team;
	team.ma_gia=p->ma_gia;
	team.ten_gia=p->ten_gia;
	team.khu_vuc=p->khu_vuc;
	team.ls=p->ls;
	//team.pnext=p->pnext;//chi thay doi vung du lieu
	
	p->ma_gia=q->ma_gia;
	p->ten_gia=q->ten_gia;
	p->khu_vuc=q->khu_vuc;
	p->ls=q->ls;
	//p->pnext=q->pnext;//chi thay doi vung du lieu

	q->ma_gia=team.ma_gia;
	q->ten_gia=team.ten_gia;
	q->khu_vuc=team.khu_vuc;
	q->ls=team.ls;	
//	q->pnext=team.pnext////chi thay doi vung du lieu
}
void sap_xep_gia(list_gia &lg)
{
    gia_sach *p=lg.phead;
	if(lg.ptail==NULL)//list_gia rong
		return;
    while(p!=lg.ptail)
    {
        gia_sach *q=p->pnext;
        while(q!=NULL)
        {
            if(q->ma_gia < p->ma_gia)
            {
            	hoanvigia(p,q);
            }
            q=q->pnext;
        }
        p=p->pnext;
    }
}
void hoanvisach(list_sach &ls)
{
	if(ls.ptail==NULL)//list_sach rong
		return;
	if(ls.phead==ls.ptail)//list_sach co 1 phan tu
		return;
	sach *p=ls.phead;//tro toi dau list_sach
	while(p!=NULL)
	{
		sach *q=p->pnext;
		while(q!=NULL)
		{
			if(q->ma_sach <p->ma_sach)
			{
				sach team;
				team.ma_sach=p->ma_sach;
				team.ten_sach=p->ten_sach;
				team.gia_ban=p->gia_ban;
				team.tac_gia=p->tac_gia;
				team.nxb=p->nxb;
				team.nam_xb=p->nam_xb;
				
				p->ma_sach=q->ma_sach;
				p->ten_sach=q->ten_sach;
				p->gia_ban=q->gia_ban;
				p->tac_gia=q->tac_gia;
				p->nxb=q->nxb;
				p->nam_xb=q->nam_xb;
				
				q->ma_sach=team.ma_sach;
				q->ten_sach=team.ten_sach;
				q->gia_ban=team.gia_ban;
				q->tac_gia=team.tac_gia;
				q->nxb=team.nxb;
				q->nam_xb=team.nam_xb;
			}
			q=q->pnext;
		}
		p=p->pnext;
	}
}
void sap_xep_sach(list_gia &lg,int ma_gia)
{
	gia_sach *p=lg.phead;
	if(lg.ptail==NULL)
		return;
	while(p!=NULL)
	{
		if(p->ma_gia==ma_gia)
		{
			hoanvisach(p->ls);
		}
		p=p->pnext;	
	}
}
void intoanbosach(list_gia lg)
{
	if(lg.ptail==NULL)
	{
		cout<<"Trong kho chua co cuon sach nao !!!\n";
		Init(lg);
		return;
	}
	gia_sach *gs=lg.phead;// tro toi dau gia sach
	cout<<"\t\t\t\tIN TOAN BO SACH\n";
	int dem=1;
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<" STT "<<"| "<<" MA SACH "<<" | "<<"  TEN SACH  "<<" | "<<" GIA BAN "<<"| ";
	cout<<"   TAC GIA   "<<" | "<<"  NXB  "<<" | "<<"NAM XB"<<" | ";
	while(gs!=NULL)
	{
		sach *s=gs->ls.phead;//tro toi dau list_sach
		while(s!=NULL)
		{
			cout<<"-------------------------------------------------------------------------------\n";
			cout<<"  "<<dem<<"  |"<<setw(10)<<s->ma_sach<<" | "<<setw(12)<<s->ten_sach<<" | "<<setw(8)<<s->gia_ban;
			cout<<" | "<<setw(13)<<s->tac_gia<<" | "<<setw(7)<<s->nxb<<" | "<<setw(6)<<s->nam_xb<<" | ";
		 	dem++;
			s=s->pnext;
		}
		gs=gs->pnext;
	}
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<"Tong sach co trong kho la: "<<(dem-1)<<" cuon.\n";
}
void sua_thongtin_gia(list_gia &lg,int ma_gia)
{
	if(lg.ptail==NULL)
		return;
	gia_sach *gs=lg.phead;//tro toi dau gia sach
	while(gs!=NULL)
	{
		if(gs->ma_gia==ma_gia)
		{
			string ten_gia;
    		string khu_vuc;
    		fflush(stdin);
		 	cout<<"TEN GIA: ";
		    getline(cin,ten_gia);
	     	gs->ten_gia=ten_gia;
	     	fflush(stdin);
		    cout<<"KHU VUC: ";
		    getline(cin,khu_vuc);
		    gs->khu_vuc=khu_vuc;
			break;
		}
		gs=gs->pnext;
	}
}
void sua_thongtin_sach(list_gia &lg,int ma_sach)
{
	if(lg.ptail==NULL)
		return;
	gia_sach *gs=lg.phead;
	while(gs!=NULL)
	{
		sach *s=gs->ls.phead;//tro toi dau list_sach
		while(s!=NULL)
		{
			if(s->ma_sach==ma_sach)
			{
		 		string ten_sach;
			    float gia_ban;
			    string tac_gia;
			    string nxb;
			    int nam_xb;
		     	fflush(stdin);
				cout<<"TEN SACH: ";
			    getline(cin,ten_sach);
			    fflush(stdin);
			    cout<<"GIA BAN: ";
			    cin>>gia_ban;
			    fflush(stdin);
			    cout<<"TAC GIA: ";
			    getline(cin,tac_gia);
			    cout<<"NHA XUAT BAN: ";
			    getline(cin,nxb);
			    fflush(stdin);
			    cout<<"NAM XUAT BAN: ";
			    cin>>nam_xb;
				s->ten_sach=ten_sach;
				s->gia_ban=gia_ban;
				s->tac_gia=tac_gia;
				s->nxb=nxb;
				s->nam_xb=nam_xb;	
			    break;
			}
			s=s->pnext;
		}
		gs=gs->pnext;	
	}
}
sach *picknode(list_sach &ls)
{
	if(ls.ptail==NULL)
		return NULL;
	sach *s=ls.phead;
	while(s!=NULL)
	{
		if(s->pnext!=NULL)//co nhieu hon 1 node
		{
			ls.phead=s->pnext;
			(s->pnext)->pre=NULL;
			s->pnext=NULL;
			return s;
		}
		ls.phead=ls.ptail=NULL;
		return s;
	}
}
void chuyen_sach(list_gia &lg,int ma_gia1,int ma_gia2)
{
	if(lg.ptail==NULL)
		return;
	gia_sach *gs=lg.phead;//tro toi dau gia sach
	while(gs!=NULL&&(gs->ls.ptail!=NULL))
	{
		if(gs->ma_gia==ma_gia1)
		{
			sach *s=picknode(gs->ls);//lay ra tung node 1
			gia_sach *gs2=lg.phead;//tro toi dau gia sach
			while(gs2!=NULL)
			{
				if(gs2->ma_gia==ma_gia2)
				{
					add_sach(gs2->ls,s);
				}
				gs2=gs2->pnext;
			}	
			continue ;
		}
		gs=gs->pnext;
	}
}
void luu_file(list_gia &lg,fstream &ghi)
{
	gia_sach *p=lg.phead;
	ghi.open("Warehouse.txt",ios::out);
	
	ghi<<dem_gia(lg)<<"\n";
	while(p!=NULL)
	{	
		ghi<<p->ma_gia<<"\n";
		ghi<<p->ten_gia<<"\n";
		ghi<<p->khu_vuc<<"\n";
		ghi<<dem_sach(p->ls)<<"\n";
		sach *q=p->ls.phead;
		while(q!=NULL)
		{
			ghi<<q->ma_sach<<"\n";
			ghi<<q->ten_sach<<"\n";
			ghi<<q->gia_ban<<"\n";
			ghi<<q->tac_gia<<"\n";
			ghi<<q->nxb<<"\n";
			ghi<<q->nam_xb<<"\n";
			q=q->pnext;	
		}
		p=p->pnext;
	}	
	ghi.close();
}
void doc_file(list_gia &lg)
{
		fstream doc;
		doc.open("Warehouse.txt",ios::in);	
		string dem_g;
		getline(doc,dem_g);//dem so gia_sach
		int d1=atoi(dem_g.c_str());//ep kieu string sang kieu int
		cout<<d1;
		for(int j=0;j<d1;j++)
		{
			string ma_gia,ten_gia,khu_vuc,dem;
			getline(doc,ma_gia);//ep kieu string sang kieu int
			int ma_g=atoi(ma_gia.c_str());
			getline(doc,ten_gia);
			getline(doc,khu_vuc);
			gia_sach *gs;	
			gs=tao_gia(ma_g,ten_gia,khu_vuc);
			add_gia(lg,gs);
		 	getline(doc,dem);//dem so sach trong moi gia
		 	int d2=atoi(dem.c_str());
		 	cout<<d2;
		 	for(int i=0;i<d2;i++)
	 		{
			 	string ma_sach,ten_sach,gia_ban,tac_gia,nxb,nam_xb;
				getline(doc,ma_sach);
				int ma_s=atoi(ma_sach.c_str());//ep kieu string sang kieu int
				getline(doc,ten_sach);
				getline(doc,gia_ban);
				float gia_b=atof(gia_ban.c_str());//ep kieu string sang kieu float
				getline(doc,tac_gia);
				getline(doc,nxb);
				getline(doc,nam_xb);
				int nam=atoi(nam_xb.c_str());
				sach *s;
				s=tao_sach(ma_s,ten_sach,gia_b,tac_gia,nxb,nam);
				add_sach(gs->ls,s);
 			}	
		}
		doc.close();
}
int dem_gia(list_gia &lg)
{
	gia_sach *p=lg.phead;
	if(p==NULL)
		return 0;
	int dem=0;
	while(p!=NULL)
	{
		dem++;
		p=p->pnext;
	}
	return dem;
}
int dem_sach(list_sach &ls)
{
	sach *s=ls.phead;
	int dem=0;
	if(s==NULL)
		return 0;
	while(s!=NULL)
	{
		dem++;
		s=s->pnext;
	}
	return dem;
}
