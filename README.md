# TextEditor_QTCreator

## How to run code

1. Select File > Open File or Project (Ctrl+O or Cmd+O on macOS)
2. Select the project file for the project to open: .pro (qmake), CMakeLists.txt (CMake), .qbs (Qbs), meson.build (Meson), pyproject (Python), or Makefile.am (Autotools, experimental).
3. In the Configure Project tab, select kits for building and running your project.
4. Select Configure Project.
5. Try Running the code {Ctrl+R}

---

## What has been done

- Added basic functionalities of a text editor

  1. **New File**
     - Setting current text to an empty string
       ```cpp
       ui->textEdit->setPlainText("");
       ```
  2. **Open File**

     - Asking for file name using dialog box
       ```cpp
       QFileDialog::getOpenFileName(this,"Open a file");
       ```
     - Setting Global File name to selected file

       ```cpp
       mFilename = file;
       // Taking all data into a in stream
       QTextStream in(&sFile);

       //Reading that data
       QString text = in.readAll();
       sFile.close();

       //Setting the read data to text
       ui->textEdit->setPlainText(text);
       ```

  3. **Save**

     - Setting out stream of file to save

       ```cpp
       QTextStream out(&sFile);

       out << ui->textEdit->toPlainText();

       sFile.flush();
       sFile.close();
       ```

  4. **Save As**
     - Asking for a file name in a dialog box
       ```cpp
       QString file = QFileDialog::getSaveFileName(this,"Open a file");
       ```
  5. **Copy**
     ```cpp
     ui->textEdit->copy();
     ```
  6. **Cut**
     ```cpp
     ui->textEdit->cut();
     ```
  7. **Paste**
     ```cpp
     ui->textEdit->paste();
     ```
  8. **Undo**
     ```cpp
     ui->textEdit->undo();
     ```
  9. **Redo**
     ```cpp
     ui->textEdit->redo();
     ```
  10. **Bold**

      ```cpp
      // Saving font weight in a local varaible
      int font = ui->textEdit->fontWeight();

      //First check if the font weight is not equal to the weight of BOLD
      if(font != QFont::Bold){
          // Then set the selected text to bold

          ui->textEdit->setFontWeight(QFont::Bold);
      }
      // If it is equal
      else{
          // If it is equal then set text to normal {UnBold feature}
          ui->textEdit->setFontWeight(QFont::Normal);
      }

      ```

  11. **SubScript and SubScript**

      ```cpp
      //Added scripting to a local variable
      //And then setting that formatting with the current format
      auto isSubscript = ui->textEdit->currentCharFormat();

      // Will check whether the current format is subscript
      if(isSubscript.verticalAlignment() != QTextCharFormat::AlignSubScript){
          // no
          // turn current format to subscript
          QTextCharFormat format;
          format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
          ui->textEdit->setCurrentCharFormat(format);
      }
      else{
          // yes
          // turn current format back to normal
          QTextCharFormat format;
          format.setVerticalAlignment(QTextCharFormat::AlignNormal);
          ui->textEdit->setCurrentCharFormat(format);
      }

      //----------------------------------------------------------------

      // Similar to subscript
      // Current format will change
      auto isSubscript = ui->textEdit->currentCharFormat();

      if(isSubscript.verticalAlignment() != QTextCharFormat::AlignSuperScript){
          QTextCharFormat format;
          format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
          ui->textEdit->setCurrentCharFormat(format);
      }
      else{
          QTextCharFormat format;
          format.setVerticalAlignment(QTextCharFormat::AlignNormal);
          ui->textEdit->setCurrentCharFormat(format);
      }
      ```

---

## Issues / Challenges

- _Issue 1_ : Adding QPdfView library giving error of not finding the library.
- _Issue 2_ : Current format is changed while using **Bold, SubScript, SuperScript**, Selected text may not change because,
  `setCurrentCharFormat` is used rather than `mergeCharFormat`.

- _Challenge 1_ : Adding my Resume is bit challenging now but still finding a way to do that.
