Notifer
--------

**A Simple Qt based message notifier**

Listens at a port for the message to be displayed and Works on Qtimer to display notifications.

**Compiling :**

qmake .
make

**Running :**

./notifier

and in a new tab

echo "Hello" | nc localhost 4000
