/*
 * picom-conf - GUI configuration tool for picom X composite manager
 * Copyright (C) 2013-2018  Hong Jen Yee (PCMan) and LXQt team (as compton-conf)
 * Copyright (C) 2021 Andrea Zanellato <redtid3@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <libconfig.h>

namespace Ui
{
  class MainDialog;
}

class QAbstractButton;

class MainDialog : public QDialog
{
  Q_OBJECT

public:
  MainDialog(QString userConfigFile = QString());
  ~MainDialog();

  virtual void done(int res);

private:
  void saveConfig();
  void updateShadowColorButton();

  void configSetInt(const char* key, int val);
  void configSetFloat(const char* key, double val);
  void configSetBool(const char* key, bool val);
  void configSetString(const char* key, const char* val);

  void createWintypesTab();

private Q_SLOTS:
  void onButtonToggled(bool checked);
  void onSpinValueChanged(double d);
  void onSpinValueChanged(int i);
  void onDialogButtonClicked(QAbstractButton* button);
  void onColorButtonClicked();
  void onAboutButtonClicked();
  void onRadioGroupToggled(bool checked);

private:
    void onWintypeBoolClicked(bool);
    void onWintypeOpacityChanged(double);

  Ui::MainDialog* ui;
  config_t config_;
  QString userConfigFile_;
  QColor shadowColor_;
};

#endif // MAINDIALOG_H
