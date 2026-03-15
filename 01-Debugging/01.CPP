#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enQuizzLevel
{
    Easy = 1,
    Med = 2,
    Hard = 3,
    Mix = 4
};
enum enOperationType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    Mix = 5
};

struct stQuestions
{
    enOperationType OperationType;
    enQuizzLevel QuizzLevel;
    int Number1 = 0;
    int Number2 = 0;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuizz
{

    stQuestions QuestionsList[100];
    enQuizzLevel QustionsLevel;
    enOperationType OperationType;
    short NumberOfQuestions;
    short NumberOfRightAnswer = 0;
    short NumberOfWorngAnswer = 0;
    bool isPass = true;
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

short ReadQuestionNumber()
{

    short NumberOfQustions;

    do
    {

        cout << "How Many Quastion Do You Want To Answer From 1 To 10: ";
        cin >> NumberOfQustions;

    } while (NumberOfQustions < 1 || NumberOfQustions > 10);

    return NumberOfQustions;
}

enQuizzLevel ReadQuestionLevel()
{

    short QuestionLevel = 0;

    do
    {

        cout << "\nEnter Questions Level [1]: Easy, [2]: Med, [3]: Hard, [4]: Mix ?";
        cin >> QuestionLevel;

    } while (QuestionLevel < 1 || QuestionLevel > 4);

    return (enQuizzLevel)QuestionLevel;
}

enOperationType ReadOperationType()
{
    short OperationType;

    do
    {

        cout << "\nEnter Operations Type [1]: Add, [2]: Sub, [3]: Mul, [4]: Div, [5]: Mix ?";
        cin >> OperationType;

    } while (OperationType < 1 || OperationType > 5);

    return (enOperationType)OperationType;
}

void PrintQuestion(short Number)
{
    for (int i = 0; i <= Number; i++)
    {
        cout << "Question [" << i << "/" << Number << "] ";
    }
}
void RandomQustionNumbers(enum enQuizzLevel)
{
    for (int i = 0; i < 6; i++)
    {
        RandomNumber(1, 100);
    }
}
enOperationType GetRandomOPType(){

}

int SimpleCalculator(){

}
stQuestions GenerateQuestion(enQuizzLevel QuizzLevel, enOperationType OpType){

    stQuestions Question;

    if (QuizzLevel == enQuizzLevel::Mix){
        QuizzLevel = (enQuizzLevel) RandomNumber(1, 3);
    }
    if (OpType == enOperationType::Mix){
        OpType = GetRandomOPType();
    }

    Question.OperationType = OpType;

    switch (QuizzLevel)
    {
    case enQuizzLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number1 = RandomNumber(1, 10);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2 , Question.OperationType);
        return Question;

        case enQuizzLevel::Med:
        /* code */
        break;

        case enQuizzLevel::Hard:
        /* code */
        break;

        case enQuizzLevel::Mix:
        /* code */
        break;
    
    default:
        break;
    }
}

void GeneratQuizzQuestions(stQuizz& Quizz)
{

    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        Quizz.QuestionsList[Question] = GenerateQuestion(Quizz.QustionsLevel, Quizz.OperationType);
    }
}

void ShowFinalQuizzScreen()
{
    cout << "\n\t\t__________________________________________________________\n\n";
    cout << "\t\t\t\t+++ F I N A L  R E S U L T S +++\n";
    cout << "\t\t__________________________________________________________\n\n";
}
void PrintQuizzReults()
{
    cout << "\t\tNumber of Questions     : ";
    cout << "\t\tQustions Level          : ";
    cout << "\t\tOperation Type          : ";
    cout << "\t\tNumber Of Right Answer  : ";
    cout << "\t\tNumber Of Worng Answer  : ";
    cout << "\t\t__________________________________________________________\n";
}

void PlayMathGame()
{

    stQuizz Quizz;

    Quizz.NumberOfQuestions = ReadQuestionNumber();
    Quizz.QustionsLevel = ReadQuestionLevel();
    Quizz.OperationType = ReadOperationType();

    GeneratQuizzQuestions(Quizz);
}

void ClearScreen()
{
    cout << "\033[2J\033[1;1H";
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ClearScreen();
        PlayMathGame();

        cout << "\nDo You Want To Play Again ? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{

    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}