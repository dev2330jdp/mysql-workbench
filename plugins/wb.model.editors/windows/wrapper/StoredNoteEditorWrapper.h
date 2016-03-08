/* 
 * Copyright (c) 2009, 2014, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#pragma once

#include "wb_editor_storednote.h"
#include "GrtTemplates.h"
#include "DelegateWrapper.h"


#pragma make_public(StoredNoteEditorBE)

namespace MySQL {
namespace Grt {

public delegate void TextChangeDelegate(int line, int linesAdded);

public ref class StoredNoteEditorWrapper : public BaseEditorWrapper
{
private:
  bool _is_script;

protected:
  StoredNoteEditorWrapper(StoredNoteEditorBE *inn);

public:
  StoredNoteEditorWrapper(MySQL::Grt::GrtValue^ arglist);
  ~StoredNoteEditorWrapper();

  StoredNoteEditorBE *get_unmanaged_object();
  void commit_changes();
  void load_text();
  void set_name(String ^name);
  String^ get_name();
  bool is_sql_script();
};

} // namespace Grt
} // namespace MySQL
