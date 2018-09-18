#include <QApplication>
#include <QSplitter>
#include <QTreeView>
#include <QListView>
#include <QFileSystemModel>
#include <QModelIndex>


int main(int argc,char* argv[])
{
	QApplication app(argc, argv);

	QSplitter *splitter = new QSplitter;

	QFileSystemModel* model = new QFileSystemModel;
	model->setRootPath(QDir::currentPath());

	QTreeView* tree = new QTreeView(splitter);
	tree->setModel(model);
	tree->setRootIndex(model->index(QDir::currentPath()));

	QListView* list = new QListView(splitter);
	list->setModel(model);
	list->setRootIndex(model->index(QDir::currentPath()));

	QModelIndex index = model->index(QDir::currentPath());
	QString a = QDir::currentPath();
	int rowNum = model->rowCount(index);
	int colNum = model->columnCount(index);
	QModelIndex index1 = model->index(0,0,index);
	QString text = model->data(index1,Qt::DisplayRole).toString();
	splitter->setWindowTitle("two view onto the same file system model");
	splitter->show();


	return app.exec();
}