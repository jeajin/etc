/*		 ��ȭ ���� ���α׷�			 */

#include "R.h"

typedef struct Movie{
	string stdio; // ��ȭ�� �̸�
	string now_showing; // ���� ������ ��ȭ
	string coming_soon; // ���� �������� ��ȭ
}Movie;
int check(Reservation* R, int m , int L, int C); // �¼� ���� üũ
int check(Reservation* R, int m , char L, int C); // �¼� ���� üũ
void InputMovie(Movie *M, int n);
void inline PrintMovie(Movie *M, int n , Reservation* R);
template <class	T>
int sumMoney(T sum, T cost);
void MENU(int &x, int &y);
int login();
void MovieR(Movie* M); 
int state;
int num ;
string name;
int main()
{
	int max = MAX; // �̹� �Ҵ�� �迭�� �ִ� ũ�⸦ ���� ����
	int N;
	int sum=0; //��ȭ �����ݾ�
	num = 0;  //��� �� ��ȭ �� ������ 0
	Movie* M = new Movie[max]; //��ȭ�� ������ ��� ����ü ������
	login(); // �α��α�� ������, �Ϲ� ��, VIP 3���� ���
	MovieR(M); // ��ȭ�� ����ϸ�, �����ڴ� �������� �������� �ڵ����� �⺻���� ���

	int X=15,Y=4+num ,x,y; //������Ʈ ��� ��ǥ ����
	int menu; //�޴� ���ÿ� ���� ��ȣ ����
	int m; //������ ��ȭ �󿵰� ��ȣ ����

	Reservation* R = new Reservation[max]; // ��ȭ ������ŭ R �����Ҵ�
	VIP_Reservation *VIP_R = new VIP_Reservation[max]; // ��ȭ �������� VIP_R �����Ҵ�

	while(1) // ���ѷ���
	{
		PrintMovie(M,num,R); // ��ȭ ���� ���
		x=X,y=Y; // ��ǥ�� ����
		MENU(x,y); // �޴� ���
		cin >> menu; 		
		if(menu == 1 && state==2) // �Ϲ� ��ȭ ����
		{
			char L; // ��
			int C; // ��
			y+=2;
			gotoxy(x,y);
			cout << "��ȭ���� ��ȣ�� �Է����ּ��� : ";
			cin >> m;
			m--;
			y+=2; x+=6;
			R[m].place_situation(x,y); // m���� ��ȭ �ڸ� ǥ��
			cout << "�¼��� �Է����ּ���(ex> A 1) : ";
			cin >> L >> C;

			if(check(R,m,L,C) == 99) // �Էµ� �¼��� ������ ����������
			{
				while(check(R,m,L,C) == 99) // ���� ������ ��� �ݺ�
				{
					gotoxy(x,y+7);
					cout << "                                   "; // ǥ�õ� �¼��� �����ִ� ��Ȱ
					gotoxy(x,y+7);
					cout << "�¼��� �ٽ� �Է����ּ��� : "; // �¼� �ٽ� �Է¹ޱ�
					cin >> L >> C;
					check(R,m,L,C); // ������ �´��� ��� üũ
				}
			}
			// ������ ������
			R[m].ticket(L,C); // �ش� �¼� Ƽ����
			R[m].place_situation(x,y); // �ٲ� �¼� ���
			gotoxy(x,y+9);
			cout << "���Ű� �Ϸ�Ǿ����ϴ�." ;
			gotoxy(x-1,y+10);
			
			if(M[m].coming_soon != "X") // ������ȭ�� �ִٸ�
			{	// �ش� stdio �� ������ȭ ȫ�� 
				cout << M[m].stdio <<"�� '"<<M[m].coming_soon <<"'�� ���������Դϴ�.";
				gotoxy(x,y+11);
				cout <<"���� ���� ��Ź�帳�ϴ�.";}
			VIP_R[m].ticket(L,C); // VIP Ŭ���� �����ڸ��� Ƽ���� (�ΰ��� Ŭ������ �¼��� Ƽ����)
			sum = sumMoney(sum, (int)10000);
		}
		else if(menu == 2 && state == 3) // VIP ��ȭ ����
		{
			char L;
			int C;
			y+=2;
			gotoxy(x,y);
			cout << "��ȭ���� ��ȣ�� �Է����ּ��� : ";
			cin >> m;
			m--;
			y+=2; x+=6;
			VIP_R[m].place_situation(x,y); // VIP �¼� ǥ�� (+���) �����ڸ� ǥ��
			cout << "�¼��� �Է����ּ���(ex> A 1) : ";
			cin >> L >> C;
			
			if(check(R,m,L,C) == 99) // �Էµ� �¼��� ������ ����������
			{
				do
				{
					gotoxy(x,y+7);
					cout << "                                   "; 
					gotoxy(x,y+7);
					cout << "�¼��� �ٽ� �Է����ּ��� : ";
					cin >> L >> C;
					check(R,m,L,C);
				}while(check(R,m,L,C) == 99);
			}
			// �¼��� ������ ������
			VIP_R[m].ticket(L,C); // �ش� �ڸ� Ƽ����
			VIP_R[m].place_situation(x,y); // �ٲ� �¼� ���
			gotoxy(x-4,y+9);
			VIP_R[m].discount(); // �������� ���� (VIPŬ���� ����)
			y++;
			gotoxy(x,y+10);
			cout << "���Ű� �Ϸ�Ǿ����ϴ�." ;
			gotoxy(x-1,y+11);
			if(M[m].coming_soon != "X") // ������ȭ�� �ִٸ�
			{	//�ش� studio�� ������ȭ ȫ��
				cout << M[m].stdio <<"�� '"<<M[m].coming_soon <<"'�� ���������Դϴ�.";
				gotoxy(x,y+12);
				cout <<"���� ���� ��Ź�帳�ϴ�.";}
			R[m].ticket(L,C); // �Ϲ��ڸ��� Ƽ��ǥ��
			sum = sumMoney(sum, (int)7000);
	
		}
		else if (menu == 3 ) // ���� 
		{
			gotoxy(X+4,Y+4);
			cout << "���α׷��� ����˴ϴ�.";
			break;
		}

		Sleep(3000); // 3�� ���� ��
		system("cls"); // ȭ�� �ʱ�ȭ
		gotoxy(15, 20);
		cout << "��" << sum << "�� �����ϼ̽��ϴ�";

	}

	Sleep(1000); // ���ѷ����� ����� 1�� ����
	delete[] R; // �޸� ����
	delete[] VIP_R; // �޸� ����

	//�Ҹ��� ȣ��
}
void MENU(int &x, int &y) // ��ǥ�� �ٰ��� �ٲ����ϹǷ� ���۷����� �Ű�����
{
	gotoxy(x,y);
	cout << "1.      ��ȭ �����ϱ�" ;
	y++;
	gotoxy(x,y);
	cout << "2. VIPȸ������ ��ȭ �����ϱ�" ;
	y++;
	gotoxy(x,y);
	cout << "3.         ����"<< endl;
	gotoxy(x+30,y);
	cout << "\n" <<  "\n" << "             "  << "�� ";

}
void gotoxy(int x, int y) // Ŀ���� ��ġ�� �̵���Ű�� �Լ�
{
	COORD Pos = {x-1, y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
void InputMovie(Movie *M, int n)
{
	char str[100];
	cin.clear(); // ���� ����ֱ�
	fflush(stdin); // ���� ����ֱ�
	if (n >= 0) {
		fgets(str, 2, stdin);
	}
	cout << "�� stdio : ";	
	getline(cin,M[n].stdio);
	cout << "�� now_showing : ";
	getline(cin,M[n].now_showing);
	cout << "�� coming_soon : ";
	getline(cin,M[n].coming_soon);
	cout <<"\n";

}
void inline PrintMovie(Movie *M, int n, Reservation* R)
{
	for(int i=0;i<n;i++) // ù��° ������ �Է��� ����ȣ���� ���
	{
		gotoxy(15,3+i);
		cout << (i+1) <<"��     " ;
		cout.setf(ios_base::left); // ��������
		cout.width(10); // �ʺ� 10
		cout << M[i].stdio ;
		cout.width(12);
		cout << M[i].now_showing ;
		gotoxy(47,3+i);
		cout << R[i].remain();
	}

}
int check(Reservation* R, int m , int L, int C=0)
{
		return 99;
}
int check(Reservation* R, int m , char L, int C) // ���� (���ڸ� �Է��� ���)
{
	if(L < 65 || L >68) // A~D ������ ������
		return 99;
	if(C<1 || C>9) // 1~9 ������ ������
		return 99;

	int use = R[m].USE(L, C); // �Էµ� �ڸ� ��뿩�� Ȯ��
	if(use ==1) // �Էµ� �ڸ��� ����� �ڸ����
		return 99; 
} // 99�� ������ main���� ����
int login() {	
	gotoxy(10, 2);
	cout << "ȸ����ȣ�� �Է����ּ���:";
	string id;
	cin >> id;
	if (id == "admin") { //������ ��ȣ�� �α���
		state = 1; //admin ��ȣ
		return 0;
	}
	else {
		fstream r, vr;
		string fname;
		r.open("r.txt", ios::in); //�Ϲ� ������ ȸ�������� ��� txt����
		vr.open("vr.txt", ios::in); //VIP ������ ȸ�������� ��� txt����

		while (r >> fname) {	//���Ͽ��� �� �б�
			if (id == fname) {	//���ϳ��ο� �Է��� ������ �ִ��� Ȯ��
				state = 2;	    //�Ϲ� ������ȣ
				name = fname;
				system("cls");;
				return 0;
			}
		}
		while (vr >> fname) {	//���Ͽ��� �� �б�
			if (id == fname) {	//���ϳ��ο� �Է��� ������ �ִ��� Ȯ��
				state = 3;		//VIP ������ȣ
				name = fname;
				system("cls");
				return 0;
			}
		}
	}
	return 0;
}

void MovieR(Movie* M) { //��ȭ�� ����ϴ� �Լ�
	if (state == 1) { //�����ڰ� �������
		int N;
		int max = MAX;
		cout << "              ��ȭ������ �Է��ϼ���";
		cout << endl;
		while (1)
		{
			if (num == max)
			{
				try {
					max += 1;
					Movie* temp = new Movie[max]; // �Ҵ�� ũ�⸸ŭ ���ο� ����ü������ temp �����Ҵ�
					memcpy(temp, M, (num) * sizeof(Movie)); // ���ڿ� ������
					//delete M; // �������� �Ҵ��� M �Ҵ� ����
					M = temp;
				}
				catch (exception e) { continue; }
			}

			for (int i = num; i < max; i++)
			{
				InputMovie(M, i);
				num++;
			}

			cout << "��ȭ������ �� �Է��Ͻðڽ��ϱ�? (1.Yes, 2.No)";
			cin >> N;
			cout << "\n";

			if (N == 2) // NO �Է½� ���ѷ��� ����
				break;

		} // while ����

		cout << "��ȭ������ ��� �Է��ϼ̽��ϴ�. " << endl;
		cout << "��ȭ ���� ���α׷��� �����ϰڽ��ϴ�." << endl;
		Sleep(700);
	}
	else if(num==0){ //�����ڰ� �ƴҰ�� ������ ��ȭ ���
		Movie* temp = new Movie[2]; 
		memcpy(temp, M, (1) * sizeof(Movie));
		M[0].stdio = "fox";
		M[0].now_showing = "���ε�";
		M[0].coming_soon = "�عٶ��";
		M[1].stdio = "showbox";
		M[1].now_showing = "����";
		M[1].coming_soon = "��ٿ�Ÿ��";
		num += 2;
	}
	system("cls");
}
template <class	T>
int sumMoney(T sum, T cost) { //�������Լ�
	sum+=cost;
	return (int)sum;
}