#include "demographics.h"
#include "ui_demographics.h"

Demographics::Demographics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demographics)
{
    ui->setupUi(this);


    //this part removes the red stars which will only show up if no data is present
    setErrorStars(false);
}

//destructor
Demographics::~Demographics()
{
    delete ui;
}


//logic to select only a male or female radio button, but not both
void Demographics::on_female_clicked()
{
    if (ui->male->isChecked())
        ui->male->setChecked(false);
    else
        ui->female->setChecked(true);
}

void Demographics::on_male_clicked()
{
    if(ui->female->isChecked())
        ui->female->setChecked(false);
    else
        ui->male->setChecked(true);
}

void Demographics::on_quit_clicked()
{
    bool inputError = false;
    //defines variables in relation to objects to allow for better error checking code
    name = ui->name->displayText();
    id = ui->id->value();
    age =ui->age->currentText();
    bool male = ui->male->isChecked();
    bool female = ui->female->isChecked();
    bool eastasian = ui->eastasian->isChecked();
    bool southasian =  ui->southasian->isChecked();
    bool black = ui->black->isChecked();
    bool caucasian = ui->caucasian->isChecked();
    bool hispanic = ui->hispanic->isChecked();
    bool middleeastern = ui->middleeastern->isChecked();
    bool other = ui->other->isChecked();
    faculty = ui->cbFaculty->currentText();
    program = ui->teProgram->text();

    /*the below block does the following:
      checks whether the items are blank, and if so,
      graphically indicates that the field needs to be filled in
      additionally, it will also create some public variables if the
      data is validated, so that they can be written to a file
    */

    if(name == "")
    {
        inputError = true;
        ui->nameerror->setVisible(true);
    }
    else
    {
        ui->nameerror->setVisible(false);
    }
    if(id == 0)
    {
        inputError = true;
        ui->iderror->setVisible(true);
    }
    else
    {
        ui->iderror->setVisible(false);
    }
    if(age == "0")
    {
        inputError = true;
        ui->ageerror->setVisible(true);
    }
    else
    {
        ui->ageerror->setVisible(false);
    }
    if(!(male || female))
    {
        inputError = true;
        ui->sexerror->setVisible(true);
    }
    else
    {
        //sets the gender flag so that we can write the data to a file
        if(male)
        {
            gender = "male";
        }
        else if (female)
        {
            gender = "female";
        }
        ui->sexerror->setVisible(false);
    }
    if(!( eastasian  ||  southasian  ||
          black  ||  caucasian  ||
          hispanic  ||  middleeastern  ||
       ( other && ui->othertext->displayText() != "")))
    {
        inputError = true;
        ui->ethnicityerror->setVisible(true);
    }
    else
    {
        //sets the ethnicity flag so that we can write the data to a file
        if(eastasian)
        {
            ethnicity = "eastasian";
        }
        else if(southasian)
        {
            ethnicity = "southasian";
        }
        else if(black)
        {
            ethnicity ="black";
        }
        else if(caucasian)
        {
            ethnicity ="caucasian";
        }
        else if(hispanic)
        {
            ethnicity ="hispanic";
        }
        else if(middleeastern)
        {
            ethnicity ="middleeastern";
        }
        else if(other)
        {
            ethnicity ="other:"+ ui->othertext->displayText();
        }
        ui->ethnicityerror->setVisible(false);
    }
    if(faculty=="")
    {
        inputError = true;
        ui->lbFacultyError->setVisible(true);
    }
    else
    {
        ui->lbFacultyError->setVisible(false);
    }

//error handling finished, now we write to file by emitting a signal which is picked up in mainwindow.cpp:
    if(inputError)
    {
        return;
    }
    else
    {
        data.writeDemographics(id, name, age, gender, ethnicity, faculty);
        virtuale.start(id);
        this->hide();
    }
}

void Demographics::setPid(int personalIdentification)
{
    //set the ID of the user to be displayed in the GUI
    ui->id->setValue(personalIdentification);
}

void Demographics::setErrorStars(bool flag)
{
    ui->nameerror->setVisible(flag);
    ui->iderror->setVisible(flag);
    ui->ageerror->setVisible(flag);
    ui->sexerror->setVisible(flag);
    ui->ethnicityerror->setVisible(flag);
    ui->lbFacultyError->setVisible(flag);
    ui->lbProgramError->setVisible(flag);
}

//get functions for gender, age, id, name, ethnicity, and faculty/program so that they can be written to a file from another class
QString Demographics::getGender()
{
    return gender;
}
QString Demographics::getAge()
{
    return age;
}
int Demographics::getId()
{
    return id;
}
QString Demographics::getName()
{
    return name;
}
QString Demographics::getEthnicity()
{
    return ethnicity;
}
QString Demographics::getFaculty()
{
    return faculty+ ":"+ program;
}
