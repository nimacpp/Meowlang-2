#!/usr/bin/env sh
echo "
   /\\_/\\
  ( o.o )  [Meowlang]
   > ^ <
"
if [ -e "/usr/bin/Meow" ]; then
    echo "=> update ..."
else
    echo "=> install ..."
fi
sudo cp Meow /usr/bin/Meow
echo "[+] done !"

