#include "forumspage.h"
#include "ui_forumspage.h"
#include "clientmodel.h"
#include "walletmodel.h"
#include "guiutil.h"
#include "guiconstants.h"
#include "util.h"

using namespace GUIUtil;

ForumsPage::ForumsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForumsPage),
    walletModel(0)
{
    ui->setupUi(this);

    // Setup header and styles
    if (fNoHeaders)
        GUIUtil::header(this, QString(""));
    else if (fSmallHeaders)
        GUIUtil::header(this, QString(":images/headerForumsSmall"));
    else
        GUIUtil::header(this, QString(":images/headerForums"));
    this->layout()->setContentsMargins(0, HEADER_HEIGHT, 0, 0);

    // buttons
    ui->back->setDisabled(true);
    ui->home->setDisabled(true);
    ui->forward->setDisabled(true);
}

ForumsPage::~ForumsPage()
{
    delete ui;
}

void ForumsPage::setModel(WalletModel *model)
{
    this->walletModel = model;
}
