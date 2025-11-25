#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	
	int idKasir,shift,pilih,noHidangan,jumlah,totalHarga,bayar,tambahMenu;
	string namaKasir[5]={"Andi","Budi","Caca","Deni","Emma"};
	int kesempatan=5;
	int jmlMenuAwal=5;
	string menu[5]={"Nasi Goreng Special","Mie Goreng Special","Ayam Geprek","Pecel Lele","Nasi Uduk"};
	int harga[5]={15000,15000,20000,18000,12000};
	string namaPembeli;
	char lanjut;
	
	while(kesempatan>0){
		cout<<left<<setw(20)<<"ID Kasir"<<": ";
		cin>>idKasir;
		if(cin.fail()){
		cin.clear();
		cin.ignore(1000, '\n');
		cout<<"\n(Mohon hanya masukkan nilai berupa angka)"<<endl;
		continue;
		}
		cout<<left<<setw(20)<<"Shift"<<": ";
		cin>>shift;
		if(cin.fail()){
		cin.clear();
		cin.ignore(1000, '\n');
		cout<<"\n(Mohon hanya masukkan nilai berupa angka)"<<endl;
		continue;
		}
		if(idKasir<6&&idKasir>0&&shift>0&&shift<4){
			cout<<"\nHalo, "<<namaKasir[idKasir-1]<<" Kamu Bekerja Pada Shift ke-"<<shift<<" Hari Ini. Semangat!"<<endl;
			break;
		}else{
			kesempatan--;
			cout<<"\nID Kasir atau Shift yang anda masukkan salah, silahkan coba kembali, kesempatan tersisa : "<<kesempatan<<endl;
		}
	}
	if(kesempatan==0){
		cout<<"\nKesempatan anda habis, \nJika anda bukan karyawan kami, mohon untuk tidak menggunakan properti kami \nTerimakasih."<<endl;
		exit(0);
	}
		
	do{
	cout<<setfill('=')<<setw(35)<<' '<<endl;
	cout<<"Kasir LEZATOS"<<endl;
	cout<<setfill('=')<<setw(35)<<' '<<endl;
	cout<<"1. Daftar Menu \n2. Pembelian Menu \n3. Tambah Data Menu \n4. Keluar \nPILIHAN : ";
	cin>>pilih;
	if(cin.fail()){
	cin.clear();
	cin.ignore(1000, '\n');
	cout<<"\n(Mohon hanya masukkan nilai berupa angka sesuai yang ada di menu kasir)"<<endl;
	continue;}
	switch(pilih){
		case 1 : cout<<endl;
			cout<<"DAFTAR HIDANGAN"<<endl;
			cout<<setfill('-')<<setw(50)<<' '<<endl;
			cout<<left<<setfill(' ')<<setw(5)<<"No"<<'|'<<setw(25)<<"Hidangan"<<'|'<<setw(20)<<"Harga"<<endl;
			cout<<setfill('-')<<setw(50)<<' '<<endl;
			for(int i=0;i<jmlMenuAwal;i++){
				cout<<left<<setfill(' ')<<setw(5)<<i+1<<'|'<<setw(25)<<menu[i]<<'|'<<setw(20)<<harga[i]<<endl;
				}
			cout<<setfill('-')<<setw(50)<<' '<<endl;
			break;
		case 2 : cout<<endl;
			cout<<"INPUT PEMBELIAN"<<endl;
			cout<<setfill('-')<<setw(50)<<' '<<endl;
			cout<<left<<setfill(' ')<<setw(30)<<"Masukkan Nama Pembeli"<<": ";
			cin.ignore();
			getline(cin, namaPembeli);
			
			do{cout<<left<<setfill(' ')<<setw(30)<<"Masukkan Nomor Hidangan"<<": ";
			cin>>noHidangan;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000, '\n');
				cout<<"\n(Mohon hanya masukkan nilai berupa angka sesuai yang tersedia di daftar menu)"<<endl;
				continue;}
			if(noHidangan<1||noHidangan>jmlMenuAwal){
				cout<<"\n(Nomor hidangan tidak tersedia, mohon masukkan ulang)"<<endl;}
			}while(noHidangan<1||noHidangan>jmlMenuAwal);
			
			do{cout<<left<<setfill(' ')<<setw(30)<<"Masukkan Jumlah"<<": ";
			cin>>jumlah;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"\n(Mohon hanya masukkan jumlah berupa angka)"<<endl;
				continue;}
			if(jumlah<=0){
				cout<<"\n(Jumlah tidak boleh nol atau negatif)"<<endl;}
			}while(jumlah<=0||cin.fail());
			totalHarga=jumlah*harga[noHidangan-1];
			
			cout<<"\nDATA PEMBELIAN"<<endl;
			cout<<setfill('-')<<setw(50)<<' '<<endl;
			cout<<left<<setfill(' ')<<setw(30)<<"Nama Pembeli"<<": "<<namaPembeli<<endl;
			cout<<left<<setfill(' ')<<setw(30)<<"Nama Hidangan"<<": "<<menu[noHidangan-1]<<endl;
			cout<<left<<setfill(' ')<<setw(30)<<"Harga Hidangan"<<": "<<harga[noHidangan-1]<<endl;
			cout<<left<<setfill(' ')<<setw(30)<<"Jumlah Pembelian"<<": "<<jumlah<<endl;
			cout<<left<<setfill(' ')<<setw(30)<<"Total Harga"<<": "<<totalHarga;
			cout<<endl;
			
			cout<<"\nINPUT PEMBAYARAN"<<endl;
			cout<<setfill('-')<<setw(70)<<' '<<endl;
			do{cout<<left<<setfill(' ')<<setw(50)<<"Masukkan Jumlah Uang Yang Dibayar"<<": ";
			cin>>bayar;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"\n(Mohon hanya masukkan nilai berupa angka/nominal)"<<endl;
				continue;}
			if(bayar<totalHarga){
				cout<<left<<setfill(' ')<<setw(50)<<"Uang Yang Anda Bayarkan Kurang"<<": "<<totalHarga-bayar<<endl;}
			}while(bayar<totalHarga);
			cout<<left<<setfill(' ')<<setw(50)<<"Kembali"<<": "<<bayar-totalHarga<<endl;
			break;
		case 3 : cout<<endl;
			cout<<"TAMBAH DATA MENU"<<endl;
			cout<<setfill('-')<<setw(70)<<' '<<endl;
			do{cout<<"Ingin tambah berapa menu? : ";
			cin>>tambahMenu;
			if(cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout<<"\n(Mohon hanya masukkan nilai berupa angka)"<<endl;
			continue;}
			}while(tambahMenu<=0 || cin.fail());
			for(int j=jmlMenuAwal;j<jmlMenuAwal+tambahMenu;j++){
				cout<<"\nData Hidangan ke-"<<j+1<<endl;
				cout<<setfill('=')<<setw(35)<<' '<<endl;
				cout<<"Masukkan Nama Hidangan : ";
				cin.ignore();
				getline(cin, menu[j]);
				while(true){
					cout<<"Masukkan Harga Hidangan : ";
					cin>>harga[j];
					if(cin.fail()){
					cin.clear();
					cin.ignore(1000, '\n');
					cout<<"\n(Mohon untuk masukkan nilai berupa angka/nominal)"<<endl;
					continue;}
					if(harga[j]<0){
					cout<<"\n(Harga tidak boleh negatif)"<<endl;
					continue;}
					break;}
				cout<<setfill('=')<<setw(35)<<' '<<endl;
			}
			cout<<"Hidangan Berhasil DItambahkan"<<endl;
			jmlMenuAwal+=tambahMenu;
			break;
		case 4 : cout<<endl;
			cout<<"\nTerimakasih Telah Menggunakan Program Kami, Semoga Harimu Menyenangkan :)"<<endl;
			break;
		default : cout<<endl;
			cout<<"Mohon untuk masukkan menu yang tersedia dinomor 1-4 saja"<<endl;
			break;
			}
			
			if(pilih==1||pilih==2||pilih==3){
				do{cout<<"\nApakah anda ingin melanjutkan program? (y/n) : ";
					cin>>lanjut;
					cout<<endl;
					if(lanjut=='n'){
						cout<<"\nTerimakasih Telah Menggunakan Program Kami, Semoga Harimu Menyenangkan :)"<<endl;}
				}while(lanjut!='y'&&lanjut!='n');}
				
		}while(pilih!=4&&lanjut=='y');
		
		return 0;	
	}
