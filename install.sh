#!/usr/bin/env sh
echo "
   /\\_/\\
  ( o.o )  [Meowlang]
   > ^ <
"
make

if [ -e "/usr/bin/Meow" ]; then
    echo "=> update ..."
else
    echo "=> install ..."
fi
sudo cp Meow /usr/bin/Meow
sudo cp Meow.1 /usr/local/share/man/man1/
echo "[+] done !"

