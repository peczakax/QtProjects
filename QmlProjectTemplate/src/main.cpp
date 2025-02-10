#include <QtGui/QGuiApplication> // Include the QGuiApplication class.
#include <QtQml/QQmlApplicationEngine> // Include the QQmlApplicationEngine class.

int main(int argc, char *argv[]) // Main function - entry point of the application.
{
    QGuiApplication application(argc, argv); // Create a QGuiApplication instance, passing command line arguments.

    QQmlApplicationEngine qmlEngine; // Create a QQmlApplicationEngine instance to handle QML.

    // Set the URL to load the main QML file.
    const QUrl qmlUrl(QStringLiteral("qrc:/qml/main.qml")); // Create a QUrl object for the main QML file.

    // Connect the objectCreationFailed signal to a lambda function that exits 
    // the application with an error code.
    QObject::connect(
        &qmlEngine, // Sender: The qmlEngine object.
        &QQmlApplicationEngine::objectCreationFailed, // Signal: Emitted if QML object creation fails.
        &application, // Receiver: The application object.
        []() { QCoreApplication::exit(-1); }, // Lambda function: Exits the application with error code -1.
        Qt::QueuedConnection // Connection type: Ensures the lambda is executed in the main thread's event loop.
    ); // Connect the signal to the lambda function.

    qmlEngine.load(qmlUrl); // Load the QML file specified by the qmlUrl.

    return application.exec(); // Start the application's event loop and return its exit code.
}
