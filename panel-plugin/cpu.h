#ifndef __XFCE_CPU_H__
#define __XFCE_CPU_H__

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <libxfce4util/libxfce4util.h>
#include <libxfcegui4/libxfcegui4.h>
#include <libxfce4panel/xfce-panel-plugin.h>
#include <libxfce4panel/xfce-hvbox.h>

#include "os.h"

#define DEFAULT_COMMAND "exo-open --launch TerminalEmulator top"

#define BORDER  8

#define MAX_WIDTH 64

typedef struct
{
	GtkWidget *m_FG1;
	GtkWidget *m_FG2;
	GtkWidget *m_FG3;
	GtkWidget *m_BG;
	GtkWidget *m_FC;
	GtkWidget *m_ColorDA;
	GtkWidget *m_ColorDA2;
	GtkWidget *m_ColorDA3;
	GtkWidget *m_ColorDA4;
	GtkWidget *m_ColorDA5;
} SOptions;

typedef struct
{
	XfcePanelPlugin *plugin;

	GtkWidget *m_FrameWidget;
	GtkWidget *m_DrawArea;
	GtkWidget *m_OptionsDialog;
	GtkWidget *m_Box;
	GtkWidget **m_pBar;
	SOptions m_Options;

	int m_UpdateInterval; // Number of ms between updates.
	int m_TimeScale; // Wether to use non-linear time scale.
	int m_Width; // The width of the plugin.
	int m_Mode; // Eventual mode of the plugin.
	int m_ColorMode;
	int m_Frame;
	gchar  *m_AssociateCommand;
	guint nrCores; // Number of cores (not including total cpu)

	GdkColor m_ForeGround1; // Inactive color.
	GdkColor m_ForeGround2; // Active color.
	GdkColor m_ForeGround3;
	GdkColor m_BackGround; // Background color.

	guint m_TimeoutID; // Timeout ID for the tooltip;
	long *m_History;
	int m_Values;
	int m_Orientation;
	CpuData *m_CpuData;

} CPUGraph;

CPUGraph *CreateControl( XfcePanelPlugin *plugin );
void Kill( XfcePanelPlugin *plugin, CPUGraph *base );
void ReadSettings( XfcePanelPlugin *plugin, CPUGraph *base );
void WriteSettings( XfcePanelPlugin *plugin, CPUGraph *base );
gboolean SetSize( XfcePanelPlugin *plugin, int size, CPUGraph *base );
void UserSetSize( CPUGraph *base );
gboolean UpdateCPU( CPUGraph *base );
void UpdateTooltip( CPUGraph *base );
void DrawGraph( CPUGraph *base );
void DrawAreaExposeEvent( GtkWidget *da, GdkEventExpose *event, gpointer data );
void CreateOptions( XfcePanelPlugin *plugin, CPUGraph *base );
void SetOrientation( XfcePanelPlugin *plugin, GtkOrientation orientation, CPUGraph *base );

gboolean LaunchCommand( GtkWidget *w, GdkEventButton *event, CPUGraph *base );
#endif
