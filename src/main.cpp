/*
 * This file is part of harbour-prayer.
 *
 * harbour-prayer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <MDeclarativeCache>
#include <QGuiApplication>
#include <QQuickView>
#include <QtQuick>
#include <QQmlError>
#include <QScopedPointer>
#include <QDebug>
#include "settings.h"

Q_DECL_EXPORT int
main(int argc, char *argv[]) {
  QScopedPointer<QGuiApplication> app(MDeclarativeCache::qApplication(argc, argv));
  QScopedPointer<QQuickView> view(MDeclarativeCache::qQuickView());

  app->setApplicationName("harbour-prayer");
  app->setApplicationDisplayName(QObject::tr("Prayer times"));

  view->setTitle(app->applicationDisplayName());
  view->setResizeMode(QQuickView::SizeRootObjectToView);
  QQmlEngine *engine = view->engine();
  QQmlContext *rootContext = engine->rootContext();

  QObject::connect(engine, SIGNAL(quit()), app.data(), SLOT(quit()));

  qmlRegisterType<Settings>("Harbour.Prayer", 1, 0, "Settings");

  view->setSource(QUrl("qrc:/qml/main.qml"));
  if (view->status() == QQuickView::Error) {
    qCritical() << "Errors loading QML:";
    QList<QQmlError> errors = view->errors();

    foreach (const QQmlError& error, errors) {
      qCritical() << error.toString();
    }

    return 1;
  }

  view->showFullScreen();

  return app->exec();
}
