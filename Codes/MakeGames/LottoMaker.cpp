#include <iostream>
#include <time.h>

using namespace std;

class Lotto
{
private:
    int maxNum;
    int lengthLotto;
    int* goalNum;
    int* userLotto;

    void makeRdNum() const
    {
        srand(static_cast<unsigned int>(time(0)));
    }
public:
    Lotto(int& leng_in, int maxnum = 45)
        : lengthLotto(leng_in), maxNum(maxnum)
    {
        goalNum = new int[lengthLotto] {0};
        userLotto = new int[lengthLotto] {0};
    }
    ~Lotto()
    {
        delete[] goalNum;
        delete[] userLotto;
    }

    unsigned int makeRdN() const    //  로또 번호 생성기
    {
        return (rand() % maxNum + 1);
    } 
    void setLotto(int*& arr, unsigned int num)        //  로또 배열에 번호 입력
    {
        for ( int i = 0; i < lengthLotto; ++i )
        {            
            arr[i] = num;
        }
        
    }  

    void makeLotto()                //  당첨 로또 생성
    {
        this->makeRdNum();
        for ( int i = 0; i < 6; ++i )
        {
            setLotto(goalNum, makeRdN());
        }
    }

    void lottoCheck()
    {
        
    }
    
    void printLotto() const
    {
        cout << "당첨 번호 : ";
        for(int i=0; i < lengthLotto; ++i)
        {
            cout << this->goalNum[i] << "\t";
        }
        cout << endl; 
        cout << "찍은 번호 : ";
        for(int i=0; i < lengthLotto; ++i)
        {
            cout << this->userLotto[i] << "\t";
        }
        cout << endl;
    }

    void lottoMaker()
    {
        makeLotto();
        printLotto();
    }
    void lottoGame()
    {
        makeLotto();
        cout << "로또 " << lengthLotto << "자리를 입력하세요 : ";
        for (int i= 0; i < lengthLotto; ++i)
        {   
            unsigned int userNum[lengthLotto]; //동적할당 하세요
                                            //나중에 delete[] 필수

            cin >> userNum[];
            setLotto(userLotto, userNum);
            printLotto(); // 디버그용
            
        }


    }
};

enum menuN
{
    LMAKER = 1,
    LGAME,
    EXIT
};

menuN printMainscreen()
{    
    int user_choice;
    cout << "!The Lotto Maker!\n\n" 
        << "1. 로또 번호 생성기\n"
        << "2. 로또 맞추기 게임\n" 
        << "3. 종료\n"
        << "원하는 기능을 선택: ";  

    cin >> user_choice;
    return menuN(user_choice);

}
void start()
{
    while(1)
    {
        menuN choice = printMainscreen();
        
        if(choice > EXIT || choice < LMAKER)
        {
            cout << "잘못된 선택입니다. 다시 선택해주세요." << endl;;
            continue;
        }
        else if (choice == 3)
        {
            cout << "종료합니다. " << endl;
            break;
        }
        else
        {
            cout << "최대 몇자리의 로또를 사용하실 건가요? : ";
            int leng;
            cin >> leng;

            Lotto game(leng);
            
            switch (choice)
            {
            case LMAKER:
            {
                int stopgo = 1 ;
                while (stopgo == 1)
                {
                    game.lottoMaker();
                    cout << "\n1. 다시 ㄱㄱ\n2.그만할래\n입력: ";
                    cin >> stopgo;
                }
                cout << "나온 번호로 1등 되세요~!" << endl;
                break;
            }
            
            case LGAME:
            {
                int stopgo = 1 ;
                while (stopgo == 1)
                {
                    game.lottoGame();  //아직 디버그용
                }
                cout << "나온 번호로 1등 되세요~!" << endl;
                break;
            }
            }
        }
        
        
        
        
    }
}

int main()
{
    start();

    return 0;
}