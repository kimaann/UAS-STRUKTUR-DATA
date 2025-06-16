#include <iostream>
#include <string>
using namespace std;

struct baju{
    string nama;
    int harga;
    string ukuran;
    baju* prev;
    baju* next;

    baju(string n, int h , string u){
        nama = n;
        harga= h;
        ukuran = u;
        prev = nullptr;
        next = nullptr;
    }

};
baju* head = nullptr;
baju* tail = nullptr;

void namaBaju(string nama, int harga, string ukuran){
    baju* baru = new baju(nama,harga, ukuran);
    if(!head){
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev =tail;
        tail = baru;
    }
    cout << " baju sudah ditambahkan.\n";
}
void tampilkanBaju(){
    if(!head){
        cout << " baju belum ditambahkan?\n";
        return;
    }else{
            baju* curr = head;
            int no =1;
            cout << " daftar baju.\n";
            while(curr){
                cout << " nama :" << curr->nama;
                cout << " harga :" << curr->harga;
                cout << " ukuran :" <<curr->ukuran << endl;
                curr= curr->next;


            }
            cout << "<<<<<<baju yang ada di toko>>>>>>>\n";
        }

}

void hapusBaju(string nama){
    baju* curr = head;
    while(curr){
        if(curr->nama == nama){
            if(curr->prev) curr->prev->next = curr->next;
            else head = curr->next;
            if(curr->next) curr->next->prev = curr->prev;
            else tail = curr->prev;
            delete curr;
            cout << "baju sudah di hapus dari toko.\n";
            return;
        }
        curr = curr-> next;
    }
    cout << " baju tidak ada di toko.\n";

}

void hapusbajulist(){
    baju* curr = head;
    while (curr){
        baju* hapus = curr;
        curr = curr-> next;
        delete hapus;
    }
{
    head = tail = nullptr;
    cout<<" semua baju sudah di hapus dari toko ini.\n";
}
}

void searchbaju(string nama){
    baju* curr = head;
    while(curr){
        if(curr->nama == nama){
            cout << "Baju ditemukan:\n";
            cout << "Nama: " << curr->nama << "\n";
            cout << "Harga: " << curr->harga << "\n";
            cout << "Ukuran: " << curr->ukuran << "\n";
            return;
        }
        curr = curr->next;
    }
    cout << "Baju tidak ditemukan.\n";
}

void swap_node(baju* a, baju* b) {
    if (!a || !b || a == b || a->next != b){
        return;
    }

    if (a->prev){
    a->prev->next = b;
    }
    else{
    head = b;
    }

    if (b->next){
    b->next->prev = a;
    }
    else{
    tail = a;
    }

    a->next = b->next;
    b->prev = a->prev;

    b->next = a;
    a->prev = b;
}


void sortshell(){
    int n=0;
    for (baju* curr = head; curr!= nullptr; curr = curr->next){
        n++;
    }
    if (!head || head == tail){
        cout << "tidak ada isinya\n";
        return;
    }
    int gap = n;
    while (gap>1){
        gap = gap/2;
        bool sudah = true;
        
        while (sudah){
            sudah = false;
            for (int i=0;i<n-gap;i++){
                baju* nodei=head;
                for (int j=0;j<i;j++){
                    nodei = nodei->next;
                }
                baju* nodej= nodei;
                for (int k=0;k<gap;k++){
                    nodej = nodej->next;
                }
                if (nodei->harga < nodej->harga){
                    swap_node(nodei, nodej);
                    sudah = true;
                }
            }
        }
    }
}

int main(){
    string nama;
    int harga;
    string ukuran;
    int pilihan;
    do{
        cout<< "1. Tambah Baju\n";
        cout<< "2. Tampilkan Baju\n";
        cout<< "3. Hapus Baju\n";
        cout<< "4. Hapus Semua Baju\n";
        cout<< "5. Cari Baju\n";
        cout<< "6. Urutkan Baju (shell)\n";
        cout<< "7. Keluar\n";
        cout<< "Pilih: ";
        cin >> pilihan; 

        switch(pilihan){
            case 1:
                cout << "Nama Baju: ";
                cin >> nama;
                cout << "Harga Baju: ";
                cin >> harga;
                cout << "Ukuran Baju: ";
                cin >> ukuran;
                namaBaju(nama, harga, ukuran);
                break;
            case 2:
                tampilkanBaju();
                break;
            case 3:
                cout << "Nama Baju yang ingin dihapus: ";
                cin >> nama;
                hapusBaju(nama);
                break;
            case 4:
                hapusbajulist();
                break;
            case 5: 
                cout << "Masukkan nama baju yang ingin dicari: ";
                cin >> nama;
                searchbaju(nama);
                break;
            case 6:
                sortshell();
                break;
            case 7:
                cout<<"Sampai jumpa!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        };
    } while(pilihan != 7);
    return 0;
};
