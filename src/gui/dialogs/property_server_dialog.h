/*  Copyright (C) 2014-2018 FastoGT. All right reserved.

    This file is part of FastoNoSQL.

    FastoNoSQL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoNoSQL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoNoSQL. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <fastonosql/core/server_property_info.h>  // for property_t

#include "gui/dialogs/base_dialog.h"

#include "proxy/proxy_fwd.h"  // for IServerSPtr

class QTableView;  // lines 26-26

namespace common {
namespace qt {
namespace gui {
class GlassWidget;
}
}  // namespace qt
}  // namespace common

namespace fastonosql {
namespace proxy {
namespace events_info {
struct ChangeServerPropertyInfoRequest;
struct ServerPropertyInfoRequest;
struct ServerPropertyInfoResponce;
struct ChangeServerPropertyInfoResponce;
}  // namespace events_info
}  // namespace proxy
namespace gui {

class PropertyServerDialog : public BaseDialog {
  Q_OBJECT

 public:
  typedef BaseDialog base_class;
  template <typename T, typename... Args>
  friend T* createDialog(Args&&... args);

  enum { min_width = 240, min_height = 200 };

 private Q_SLOTS:
  void startLoadServerProperty(const proxy::events_info::ServerPropertyInfoRequest& req);
  void finishLoadServerProperty(const proxy::events_info::ServerPropertyInfoResponce& res);

  void startServerChangeProperty(const proxy::events_info::ChangeServerPropertyInfoRequest& req);
  void finishServerChangeProperty(const proxy::events_info::ChangeServerPropertyInfoResponce& res);

  void changeProperty(const core::property_t& prop);

 protected:
  explicit PropertyServerDialog(const QString& title,
                                const QIcon& icon,
                                proxy::IServerSPtr server,
                                QWidget* parent = Q_NULLPTR);

  void showEvent(QShowEvent* e) override;

 private:
  common::qt::gui::GlassWidget* glass_widget_;
  QTableView* properties_table_;
  const proxy::IServerSPtr server_;
};

}  // namespace gui
}  // namespace fastonosql
