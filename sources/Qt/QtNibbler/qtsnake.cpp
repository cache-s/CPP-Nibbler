
#include "qtsnake.h"

QtSnake::QtSnake(QWidget *parent):QWidget(parent){
    this->setWindowTitle("Qt Nibbler");

    //WIDGETS
    QPushButton *quit = new QPushButton(tr("Exit"));
    quit->setFocusPolicy(Qt::NoFocus);
    quit->setFixedSize(100,40);
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    snakeField *snakefield = new snakeField;
    snakefield->setFocusPolicy(Qt::StrongFocus); //preselection. Obligatoire
  //  connect(snakefield, SIGNAL(quit()),qApp,SLOT(quit()));

    QLCDNumber *LCDLength = new QLCDNumber(5); //affichage de la taille du serpent
    LCDLength->setFocusPolicy(Qt::NoFocus);
    LCDLength->setSegmentStyle(QLCDNumber::Flat);
    LCDLength->setFixedSize(150,50);
    //connect(snakefield, SIGNAL(snakeLength(int)),LCDLength, SLOT(display(int)));

    QLabel *LengthLabel = new QLabel("Length :"); //affichage du label de la taille
    LengthLabel->setFocusPolicy(Qt::NoFocus);
    LengthLabel->setFixedHeight(20);

    QLabel *difficultyLabel = new QLabel("Difficulty :"); //affichage de la difficultée
    difficultyLabel->setFocusPolicy(Qt::NoFocus);
    difficultyLabel->setFixedHeight(20);

    QLabel *difficulty = new QLabel();
    difficulty->setFocusPolicy(Qt::NoFocus);
    difficulty->setFixedHeight(50);
    difficulty->setFixedWidth(170);
    difficulty->setAlignment(Qt::AlignCenter);
    difficulty->setFont(QFont("Palatino", 25, QFont::Bold));
    //connect(snakefield, SIGNAL(levelUpdated(QString)), difficulty,SLOT(setText(QString)));

    QLabel *help = new QLabel("Q/D 4/6 left/right to move snake \nP to pause the game \nR to restart\
 a game\nEsc to quit the game");
    help->setFocusPolicy(Qt::NoFocus);
    help->setAlignment(Qt::AlignLeft);

    //LAYOUT
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(LengthLabel,0,0);
    gridLayout->addWidget(LCDLength,1,0);
    gridLayout->addWidget(difficultyLabel,2,0);
    gridLayout->addWidget(difficulty,3,0);
    gridLayout->addWidget(help,5,0);
    gridLayout->addWidget(quit,6 ,0 );
    gridLayout->addWidget(snakefield,0,1,9,9);
    setLayout(gridLayout);
}
